#ifndef ARM_H
#define ARM_H

#include "politocean/pi/dcmotor.h"
#include "politocean/pi/stepper.h"

using namespace politocean::pi;

struct DCMotorConfig {
  pin_t dirPin, pwmPin;
};

struct StepperConfig {
  pin_t enPin, dirPin, stepPin;
};

class Arm {
  Stepper _shoulder, _wrist;
  DCMotor _nipper;

  bool _enabled = false;

public:
  Arm(const StepperConfig &shoulderConfig, const StepperConfig &wristConfig,
      const DCMotorConfig &nipperConfig);

  void moveShoulderUp();
  void moveShoulderDown();
  void stopShoulder();
  void rotateWristCW();
  void rotateWristCCW();
  void stopWrist();
  void openNipper();
  void closeNipper();
  void stopNipper();

  void enable();
  void disable();
  inline bool isEnabled() { return _enabled; }
};

#endif // ARM_H