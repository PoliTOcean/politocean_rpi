#include "pi.h"
#include "pigpio.h"

#include "politocean/pi/dcmotor.h"
#include "politocean/pi/pinout.h"
#include "politocean/pi/pitypes.h"
#include "politocean/pi/stepper.h"

#include "mqtt/async_client.h"
#include "yaml-cpp/yaml.h"

#include <iostream>
#include <map>

using namespace std;
using namespace politocean::pi;

const string DFLT_CONFIG_PATH = "./";

Pi::Pi() : Pi(DFLT_CONFIG_PATH) {}

Pi::Pi(const string &path) : _configured(false) {
  _configure(path);

  StepperConfig shoulderConfig = {.enPin = _pinout[Pinout::SHOULDER_EN],
                                  .dirPin = _pinout[Pinout::SHOULDER_DIR],
                                  .stepPin = _pinout[Pinout::SHOULDER_STEP]};
  StepperConfig wristConfig = {.enPin = _pinout[Pinout::WRIST_EN],
                               .dirPin = _pinout[Pinout::WRIST_DIR],
                               .stepPin = _pinout[Pinout::WRIST_STEP]};
  DCMotorConfig nipperConfig = {.dirPin = _pinout[Pinout::NIPPER_DIR],
                                .pwmPin = _pinout[Pinout::NIPPER_PWM]};

  _arm = new Arm(shoulderConfig, wristConfig, nipperConfig);
}
Pi::~Pi() {
  delete _arm;

  gpioTerminate();
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
}