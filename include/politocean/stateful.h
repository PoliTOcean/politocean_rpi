#ifndef STATEFUL_H
#define STATEFUL_H

#include <exception>
#include <string>

#include "exception.h"

using namespace std;

namespace politocean {
using namespace exception;

template <typename T, typename enable_if<is_enum<T>::value>::type * = nullptr>
class Stateful {
public:
  virtual T getState() const {
    throw NotImplementedException("Method parse has not been implemented.");
  }
  virtual void setState(const T &) {
    throw NotImplementedException("Method stringify has not been implemented.");
  }
};
} // namespace politocean

#endif // STATEFUL_H