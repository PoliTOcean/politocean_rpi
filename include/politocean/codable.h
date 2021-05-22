#ifndef CODABLE_H
#define CODABLE_H

#include <exception>
#include <string>

#include "exception.h"

namespace politocean {
using namespace exception;
class Codable {
public:
  template <typename T,
            typename std::enable_if<std::is_base_of<Codable, T>::value>::type
                * = nullptr>
  static T parse(const std::string &str) {
    throw NotImplementedException("Method parse has not been implemented.");
  }
  virtual const std::string stringify() {
    throw NotImplementedException("Method stringify has not been implemented.");
  }
};
} // namespace politocean

#endif // CODABLE_H