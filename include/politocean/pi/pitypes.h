#ifndef PI_TYPES_H
#define PI_TYPES_H

#include <cstdint>
#include <type_traits>

namespace politocean::pi {

typedef uint8_t pin_t;

enum class Direction {
  CW,
  CCW,
};

template <typename E> constexpr auto to_underlying(E e) noexcept {
  return static_cast<std::underlying_type_t<E>>(e);
}

} // namespace politocean::pi

#endif // PI_TYPES_H