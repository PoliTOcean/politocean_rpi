#include "pi.h"
#include "pigpio.h"

#include "spdlog/spdlog.h"

#include "politocean/axis.h"
#include "politocean/constants.h"

#include "politocean/pi/dcmotor.h"
#include "politocean/pi/pinout.h"
#include "politocean/pi/pitypes.h"
#include "politocean/pi/stepper.h"

#include "mqtt/async_client.h"
#include "yaml-cpp/yaml.h"

#include <iostream>
#include <map>

using namespace std;
using namespace politocean;
using namespace politocean::pi;

const string DFLT_CONFIG_PATH = "./";

Pi::Pi() : Pi(DFLT_CONFIG_PATH) {}

Pi::Pi(const string &path) : _configured(false), _spiHandle(kDFLTSPIHandle) {
  _configure(path);

  StepperConfig shoulderConfig, wristConfig;
  DCMotorConfig nipperConfig;
  tie(shoulderConfig, wristConfig, nipperConfig) = _configureArm();

  _arm = new Arm(shoulderConfig, wristConfig, nipperConfig);
  _mqttClient = new politocean::MQTTClient(_mqttConfig.address, _mqttConfig.id);
  _mqttClient->subscribeTo(constants::topics::kAxesTopic, &Pi::_handleAxis,
                           this);
  _mqttClient->subscribeTo(constants::topics::kCommandsTopic,
                           &Pi::_handleCommand, this);
  _mqttClient->connect();
}

Pi::~Pi() {
  delete _arm;
  _mqttClient->disconnect();

  if (_spiHandle >= 0) {
    closeSPI();
  }

  delete _mqttClient;
  gpioTerminate();
}

std::tuple<StepperConfig, StepperConfig, DCMotorConfig> Pi::_configureArm() {
  return {{.enPin = _pinout[Pinout::SHOULDER_EN],
           .dirPin = _pinout[Pinout::SHOULDER_DIR],
           .stepPin = _pinout[Pinout::SHOULDER_STEP]},
          {.enPin = _pinout[Pinout::WRIST_EN],
           .dirPin = _pinout[Pinout::WRIST_DIR],
           .stepPin = _pinout[Pinout::WRIST_STEP]},
          {.dirPin = _pinout[Pinout::NIPPER_DIR],
           .pwmPin = _pinout[Pinout::NIPPER_PWM]}};
}

void Pi::_configure(const string &path) {
  map<string, pin_t> pinout;

  YAML::Node config = YAML::LoadFile(path + "config.yaml");

  for (auto pin : config["pinout"]) {
    pinout.insert(
        pair<string, pin_t>(pin.first.as<string>(), pin.second.as<int>()));
  }
  _pinout = move(pinout);

  _mqttConfig.id = config["mqtt"]["id"].as<string>();
  _mqttConfig.address = config["mqtt"]["address"].as<string>();

  _configured = true;

  // startSPI();
}

void Pi::startSPI() {}

void Pi::closeSPI() {
  if (_spiHandle < 0)
    return;

  spiClose(_spiHandle);
}

void Pi::_handleCommand(const string &str) {
  spdlog::info("Got command {}", str);
  uint8_t command = constants::commands::mapIDToValue.at(str);

  switch (command) {
  case constants::commands::value::kTogglePower:
    gpioWrite(12, PI_HIGH);
    spdlog::info("Power enabled", str);
    break;
  case constants::commands::value::kToggleArm:
    _arm->isEnabled() ? _arm->disable() : _arm->enable();
    break;
  case constants::commands::value::kMoveShoulderUp:
    _arm->moveShoulderUp();
    break;
  case constants::commands::value::kMoveShoulderDown:
    _arm->moveShoulderDown();
    break;
  case constants::commands::value::kStopShoulder:
    _arm->stopShoulder();
    break;
  }
}

void Pi::_handleAxis(const string &str) {
  try {
    Axis axis = Axis::parse(str);
    spdlog::info("Got axis {} with value {}", axis.getID(), axis.getValue());
  } catch (...) {
    spdlog::error("Error on parsing axis from string {}", str);
  }
}