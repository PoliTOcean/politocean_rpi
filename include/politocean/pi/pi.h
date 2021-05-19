#ifndef PI_H
#define PI_H

#include <cstdint>

namespace politocean::pi {
#include "pigpio.h"

typedef uint8_t pin_t;

enum class Dir {
  CW,
  CCW,
};
} // namespace politocean::pi