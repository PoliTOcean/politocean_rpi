#ifndef PINOUT_H
#define PINOUT_H

#include "pitypes.h"

#include <string>

namespace politocean::pi {
class Pinout {
public:
  inline static const std::string NIPPER_DIR = "NIPPER_DIR";
  inline static const std::string NIPPER_PWM = "NIPPER_PWM";
  inline static const std::string SHOULDER_EN = "SHOULDER_EN";
  inline static const std::string SHOULDER_DIR = "SHOULDER_DIR";
  inline static const std::string SHOULDER_STEP = "SHOULDER_STEP";
  inline static const std::string WRIST_EN = "WRIST_EN";
  inline static const std::string WRIST_DIR = "WRIST_DIR";
  inline static const std::string WRIST_STEP = "WRIST_STEP";
  inline static const std::string CAMERA_EN = "CAMERA_EN";
  inline static const std::string CAMERA_DIR = "CAMERA_DIR";
  inline static const std::string CAMERA_STEP = "CAMERA_STEP";
  inline static const std::string LIGHTS_DIR = "LIGHTS_DIR";
  inline static const std::string LIGHTS_PWM = "LIGHTS_PWM";
  inline static const std::string POWER = "POWER";
};
} // namespace politocean::pi

#endif // PINOUT_H