#ifndef AXIS_H
#define AXIS_H

#include "codable.h"
#include "identifiable.h"

#include <string>

namespace politocean {
class Axis : public virtual Identifiable, public virtual Codable {
  std::string _id;
  int _value;

public:
  Axis(const std::string &id, int value);

  inline void setValue(int value) { _value = value; }
  inline int getValue() { return _value; }

  inline const std::string &getID() { return _id; }

  static Axis parse(const std::string &str);
  const std::string stringify();
};
} // namespace politocean

#endif // AXIS_H