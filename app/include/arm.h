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

public:
  Arm(const StepperConfig &shoulderConfig, const StepperConfig &wristConfig,
      const DCMotorConfig &nipperConfig);
};

#endif // ARM_H