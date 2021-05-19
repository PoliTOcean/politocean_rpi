#include "sensor.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace politocean;

Sensor::Sensor(const string &id, double value) : _id(id), _value(value) {}

void Sensor::setValue(float value) { _value = value; }
double Sensor::getValue() { return _value; }

const string &Sensor::getID() { return _id; }

Sensor Sensor::parse(const string &str) {
  nlohmann::json j = nlohmann::json::parse(str);

  string id;
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

const string Sensor::stringify() {
  nlohmann::json j;

  j[_id] = _value;

  return j.dump();
}