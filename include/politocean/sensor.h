#ifndef SENSOR_H
#define SENSOR_H

#include <string>

#include "codable.h"

using namespace std;

namespace politocean {
class Sensor : public virtual Codable {
  string _id;
  double _value;

public:
  Sensor(const string &id, double value);

  void setValue(float v);
  double getValue();

  const string &getID();

  static Sensor parse(const string &str);
  const string stringify();
};
} // namespace politocean

#endif // SENSOR_H