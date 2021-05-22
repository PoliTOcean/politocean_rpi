#include "arm.h"

Arm::Arm(const StepperConfig &shoulderConfig, const StepperConfig &wristConfig,
         const DCMotorConfig &nipperConfig)
    : _shoulder(shoulderConfig.enPin, shoulderConfig.dirPin,
                shoulderConfig.stepPin),
      _wrist(wristConfig.enPin, wristConfig.dirPin, wristConfig.stepPin),
      _nipper(nipperConfig.dirPin, nipperConfig.pwmPin) {}

void Arm::moveShoulderUp() {
  if (_shoulder.isRunning()) {
    return;
  }

  _shoulder.run(Direction::CW, 100);
}
void Arm::moveShoulderDown() {
  if (_shoulder.isRunning()) {
    return;
  }

  _shoulder.run(Direction::CCW, 100);
}
void Arm::stopShoulder() {
  if (!_shoulder.isRunning()) {
    return;
  }

  _shoulder.stop();
}
void Arm::rotateWristCW() {}
void Arm::rotateWristCCW() {}
void Arm::stopWrist() {}
void Arm::openNipper() {}
void Arm::closeNipper() {}
void Arm::stopNipper() {}

void Arm::enable() {
  if (_enabled) {
    return;
  }

  _shoulder.enable();
  _wrist.enable();

  _enabled = true;
}

void Arm::disable() {
  if (!_enabled) {
    return;
  }

  _shoulder.disable();
  _wrist.disable();

  _enabled = false;
}