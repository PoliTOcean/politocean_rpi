#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H

#include <exception>
#include <string>

#include "exception.h"

using namespace std;

namespace politocean {
using namespace exception;
class Identifiable {
public:
  virtual const string &getID() const {
    throw NotImplementedException("Method getID has not been implemented.");
  }
};
} // namespace politocean

#endif // IDENTIFIABLE_H