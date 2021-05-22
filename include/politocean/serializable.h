#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "exception.h"

#include <vector>

namespace politocean {
using namespace exception;
class Serializable {
  template <typename T, typename std::enable_if<std::is_base_of<
                            Serializable, T>::value>::type * = nullptr>
  static T parse(const std::vector<char> &serial) {
    throw NotImplementedException(
        "Serializable::parse has not been implemented.");
  }
  virtual const std::vector<char> serialize() {
    throw NotImplementedException(
        "Serializable::serialize has not been implemented.");
  }

  virtual void deserialize(const std::vector<char> &) {
    throw NotImplementedException(
        "Serializable::deserialize has not been implemented.");
  }

  virtual size_t size() const {
    throw NotImplementedException(
        "Serializable::size has not been implemented.");
  }
};
} // namespace politocean

#endif // SERIALIZABLE_H