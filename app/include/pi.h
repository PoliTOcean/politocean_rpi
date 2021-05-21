#ifndef PI_H
#define PI_H

#include <map>
#include <string>

#include "arm.h"

#include "politocean/mqtt.h"

class Pi {
  bool _configured;
  std::map<std::string, politocean::pi::pin_t> _pinout;

  Arm *_arm;

  politocean::MQTTConfig _mqttConfig;
  politocean::MQTTClient *_mqttClient;

  void _configure(const std::string &path);

public:
  Pi();
  Pi(const std::string &path);
  ~Pi();

  inline const std::map<std::string, politocean::pi::pin_t> &getPinout() {
    return _pinout;
  }
};

#endif // PI_H