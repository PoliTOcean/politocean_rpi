#ifndef CODABLE_H
#define CODABLE_H

#include <exception>
#include <string>

#include "exception.h"

using namespace std;

namespace politocean {
using namespace exception;
class Codable {
public:
  template <typename T,
            typename enable_if<is_base_of<Codable, T>::value>::type * = nullptr>
  static T parse(const string &str) {
    throw NotImplementedException("Method parse has not been implemented.");
  }
  virtual const string stringify() {
    throw NotImplementedException("Method stringify has not been implemented.");
  }
};
} // namespace politocean

#endif // CODABLE_H