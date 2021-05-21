#include "arm.h"

Arm::Arm(const StepperConfig &shoulderConfig, const StepperConfig &wristConfig,
         const DCMotorConfig &nipperConfig)
    : _shoulder(shoulderConfig.enPin, shoulderConfig.dirPin,
                shoulderConfig.stepPin),
      _wrist(wristConfig.enPin, wristConfig.dirPin, wristConfig.stepPin),
      _nipper(nipperConfig.dirPin, nipperConfig.pwmPin) {}