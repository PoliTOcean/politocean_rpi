#ifndef DCMOTOR_H
#define DCMOTOR_H

#include "pi.h"

#include "spdlog/spdlog.h"

namespace politocean::pi {
class DCMotor {
  pin_t _dirPin, _pwmPin;

public:
  DCMotor(pin_t dirPin, pin_t pwmPin);

  void run(Dir dir, uint8_t speed);
  void stop();
};
} // namespace politocean::pi

#endif // DCMOTOR_H