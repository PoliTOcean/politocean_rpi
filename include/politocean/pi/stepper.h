#ifndef STEPPER_H
#define STEPPER_H

#include "pigpio.h"
#include "pitypes.h"

#include <condition_variable>
#include <mutex>
#include <thread>

namespace politocean::pi {
class Stepper {
  pin_t _enPin, _dirPin, _stepPin;
  bool _enabled = false, _running = false;

public:
  Stepper(pin_t enPin, pin_t dirPin, pin_t stepPin);
  ~Stepper();

  void enable();
  void disable();

  void step(Direction dir);
  void run(Direction dir, unsigned int frequency);
  void stop();

  inline bool isRunning() { return _running; }
  inline bool isEnabled() { return _enabled; }
};
} // namespace politocean::pi

#endif // STEPPER_H