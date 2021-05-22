#include "sensor.h"
#include "constants.h"
#include "nlohmann/json.hpp"
#include <climits>
#include <cmath>
#include <string>
#include <tuple>

using namespace politocean;

Sensor::Sensor(const std::string &id, double value) : _id(id), _value(value) {}

Sensor Sensor::parse(const std::string &str) {
  nlohmann::json j = nlohmann::json::parse(str);

  std::string id;
  double value;

  if (j.size() > 1)
    throw ParsingException("Only one sensor allowed.\n");

  try {
    id = j.begin().key();
    value = j.begin().value();
  } catch (nlohmann::json::parse_error &ex) {
    throw ParsingException(ex.what());
  }

  return Sensor(id, value);
}

const std::string Sensor::stringify() {
  nlohmann::json j;

  j[_id] = _value;

  return j.dump();
}

Sensor Sensor::parse(const std::vector<char> &serial) {
  if (serial.size() != 2) {
    throw ParsingException(
        "Parsing error: a Sensor must contains two bytes to be parsed.\n");
  }

  return Sensor(constants::sensors::mapValueToID.at(serial[0]),
                serial[1] + serial[2] / 100.0);
}

const std::vector<char> Sensor::serialize() {
  std::tuple<double, double> number;

  std::get<1>(number) = std::modf(_value, &std::get<0>(number));

  return std::vector<char>{constants::sensors::mapIDToValue.at(_id),
                           static_cast<char>(std::get<0>(number)),
                           static_cast<char>(std::get<1>(number) * 100)};
}

void Sensor::deserialize(const std::vector<char> &s) {
  if (s.size() != kSerializableSize) {
    throw DeserilizingException(
        "Cannot deserialize object. It must be of size " + kSerializableSize);
  }

  _value = s[0] + s[1] / 100.0;
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}