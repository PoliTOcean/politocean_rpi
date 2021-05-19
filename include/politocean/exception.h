#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

namespace politocean::exception {
class ParsingException : public std::exception {
  std::string _str;

public:
  ParsingException(const std::string &str) : _str(str) {}

  virtual const char *what() const throw() { return _str.c_str(); }
};

class NotImplementedException : public std::exception {
  std::string _str;

public:
  NotImplementedException(const std::string &str) : _str(str) {}

  virtual const char *what() const throw() { return _str.c_str(); }
};
} // namespace politocean::exception

#endif // EXCEPTION_H