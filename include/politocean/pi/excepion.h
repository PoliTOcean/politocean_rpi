#ifndef PI_EXCEPTION_H
#define PI_EXCEPTION_H

#include <exception>
#include <string>

namespace politocean::pi::exception {
class GPIOException : public std::exception {
  std::string _str;

public:
  GPIOException(const std::string &str) : _str(str) {}

  virtual const char *what() const throw() { return _str.c_str(); }
};
} // namespace politocean::exception

#endif // PI_EXCEPTION_H