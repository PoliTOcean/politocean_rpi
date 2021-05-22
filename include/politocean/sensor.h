#ifndef SENSOR_H
#define SENSOR_H

#include <string>

#include "codable.h"
#include "identifiable.h"
#include "serializable.h"

namespace politocean {
class Sensor : public virtual Codable,
               public virtual Identifiable,
               public virtual Serializable {
  std::string _id;
  double _value;

  const size_t kSerializableSize = 3; // ID - Integral part - Decimal part

public:
  Sensor(const std::string &id, double value);

  inline void setValue(float value) { _value = value; }
  inline double getValue() { return _value; }

  inline const std::string &getID() const override { return _id; }

  static Sensor parse(const std::string &str);
  const std::string stringify() override;

  static Sensor parse(const std::vector<char> &serial);
  const std::vector<char> serialize() override;
  void deserialize(const std::vector<char> &) override;
  inline size_t size() const override { return kSerializableSize; }
};
} // namespace politocean

#endif // SENSOR_H