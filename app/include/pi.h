#ifndef PI_H
#define PI_H

#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "arm.h"

#include "politocean/mqtt.h"

class PiException : public std::exception {
  std::string _str;

public:
  PiException(const std::string &str) : _str(str) {}

  virtual const char *what() const throw() { return _str.c_str(); }
};
class Pi {
  const int kSPISpeed = 1000000;
  const int kSPIChannel = 0;
  const int kDFLTSPIHandle = -1;
  const char kSPIStarted = 0xff;

  bool _configured;
  std::map<std::string, politocean::pi::pin_t> _pinout;
  int _spiHandle;

  Arm *_arm;

  politocean::MQTTConfig _mqttConfig;
  politocean::MQTTClient *_mqttClient;

  std::vector<uint8_t> _spiAxis, _spiCommand;

  void _configure(const std::string &path);
  std::tuple<StepperConfig, StepperConfig, DCMotorConfig> _configureArm();

  void _handleAxis(const std::string &str);
  void _handleCommand(const std::string &str);

public:
  Pi();
  Pi(const std::string &path);
  ~Pi();

  void startSPI();
  void closeSPI();

  inline const std::map<std::string, politocean::pi::pin_t> &getPinout() {
    return _pinout;
  }
};

#endif // PI_H