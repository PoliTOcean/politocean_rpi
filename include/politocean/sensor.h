#ifndef SENSOR_H
#define SENSOR_H

#include <string>

#include "codable.h"

namespace politocean {
class Sensor : public virtual Codable {
  std::string _id;
  double _value;

public:
  Sensor(const std::string &id, double value);

  inline void setValue(float value) { _value = value; }
  inline double getValue() { return _value; }

  inline const std::string &getID() { return _id; }

  static Sensor parse(const std::string &str);
  const std::string stringify();
};
} // namespace politocean

#endif // SENSOR_H