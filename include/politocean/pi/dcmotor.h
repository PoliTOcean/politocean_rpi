#ifndef DCMOTOR_H
#define DCMOTOR_H

#include "pitypes.h"

#include <condition_variable>
#include <mutex>
#include <thread>

namespace politocean::pi {
class DCMotor {
  pin_t _dirPin, _pwmPin;
  bool _running = false;

public:
  DCMotor(pin_t dirPin, pin_t pwmPin);
  ~DCMotor();

  void run(Direction dir, uint8_t speed);
  void stop();
  inline bool isRunning() { return _running; };
};
} // namespace politocean::pi

#endif // DCMOTOR_H