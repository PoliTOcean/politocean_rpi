#ifndef COMMAND_H
#define COMMAND_H

#include "codable.h"

#include <string>

namespace politocean {
class Command : public virtual Codable {
  std::string _action, _component;
  int _value;

public:
  Command(const std::string &action, const std::string &component, int value);

  inline const string &getAction() { return _action; }
  inline const string &getComponent() { return _component; }
  inline int getValue() { return _value; }

  static Command parse(const std::string &str);
  const std::string stringify();
};
} // namespace politocean

#endif // COMMAND_H