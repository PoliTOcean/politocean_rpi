#include "pigpio.h"

#include "excepion.h"
#include "stepper.h"

#include <chrono>
#include <iostream>
#include <thread>

using namespace politocean::pi;
using namespace politocean::pi::exception;

Stepper::Stepper(pin_t enPin, pin_t dirPin, pin_t stepPin)
    : _enPin(enPin), _dirPin(dirPin), _stepPin(stepPin) {
  if (gpioInitialise() < 0) {
    throw GPIOException("PiGPIO initialisation failed in Stepper.\n");
  }

  gpioSetMode(enPin, PI_OUTPUT);
  gpioSetMode(dirPin, PI_OUTPUT);
  gpioSetMode(stepPin, PI_OUTPUT);
}

Stepper::~Stepper() { disable(); }

void Stepper::enable() {
  if (gpioInitialise() < 0) {
    throw GPIOException("PiGPIO initialisation failed in Stepper::enable.\n");
  }

  gpioWrite(_enPin, PI_HIGH);
}

void Stepper::disable() {
  if (gpioInitialise() < 0) {
    throw GPIOException("PiGPIO initialisation failed in Stepper::disable.\n");
  }

  stop();

  gpioWrite(_enPin, PI_LOW);
}

void Stepper::run(Direction dir, unsigned int frequency) {
  if (gpioInitialise() < 0) {
    throw GPIOException("PiGPIO initialisation failed in Stepper::run.\n");
  }

  gpioWrite(_dirPin, to_underlying(dir));

  gpioSetPWMfrequency(_stepPin, frequency);
  gpioPWM(_stepPin, gpioGetPWMrange(_stepPin) / 2);
}

void Stepper::step(Direction dir) {
  if (gpioInitialise() < 0) {
    throw GPIOException("PiGPIO initialisation failed in Stepper::run.\n");
  }

  gpioWrite(_dirPin, to_underlying(dir));

  std::thread thread([&] {
    gpioWrite(_stepPin, PI_HIGH);
    std::this_thread::sleep_for(std::chrono::microseconds(20));
    gpioWrite(_stepPin, PI_LOW);
    std::this_thread::sleep_for(std::chrono::microseconds(20));
  });
  thread.detach();
}

void Stepper::stop() {
  if (gpioInitialise() < 0) {
    throw GPIOException("PiGPIO initialisation failed in Stepper::run.\n");
  }

  gpioWrite(_dirPin, PI_LOW);
  gpioPWM(_stepPin, 0);
}