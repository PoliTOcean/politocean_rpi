#include "dcmotor.h"

using namespace politocean::pi;

DCMotor::DCMotor(pin_t dir, pin_t pwm) : _dir(dir), _pwm(pwm) {}