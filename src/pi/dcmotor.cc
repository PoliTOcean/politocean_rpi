#include "pigpio.h"

#include "dcmotor.h"
#include "exception.h"

using namespace politocean::pi;
using namespace politocean::pi::exception;

DCMotor::DCMotor(pin_t dirPin, pin_t pwmPin)
    : _dirPin(dirPin), _pwmPin(pwmPin) {
  if (gpioInitialise() < 0) {
    throw GPIOException("PiGPIO initialisation failed in PiMotor::run.\n");
  }

  gpioSetMode(_dirPin, PI_OUTPUT);
  gpioSetMode(_pwmPin, PI_OUTPUT);
}

DCMotor::~DCMotor() { stop(); }

void DCMotor::run(Direction dir, uint8_t speed) {
  if (_running) {
    return;
  }

  if (gpioInitialise() < 0) {
    throw GPIOException("PiGPIO initialisation failed in DCMotor::run.\n");
  }

  gpioWrite(_dirPin, to_underlying(dir));
  gpioPWM(_pwmPin, speed);

  _running = true;
}

void DCMotor::stop() {
  if (!_running) {
    return;
  }

  if (gpioInitialise() < 0) {
    throw GPIOException("PiGPIO initialisation failed in DCMotor::run.\n");
  }

  gpioWrite(_dirPin, PI_LOW);
  gpioPWM(_pwmPin, 0);

  _running = false;
}