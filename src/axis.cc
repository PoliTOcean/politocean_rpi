#include "axis.h"
#include "nlohmann/json.hpp"

#include <string>

using namespace std;
using namespace politocean;

Axis::Axis(const string &id, int value) : _id(id), _value(value) {}

Axis Axis::parse(const string &str) {
  nlohmann::json j = nlohmann::json::parse(str);

  string id;
  double value;

  if (j.size() > 1)
    throw ParsingException("Only one axis allowed.\n");

  try {
    id = j.begin().key();
    value = j.begin().value();
  } catch (nlohmann::json::parse_error &ex) {
    throw ParsingException(ex.what());
  }

  return Axis(id, value);
}

const string Axis::stringify() {
  nlohmann::json j;

  j[_id] = _value;

  return j.dump();
}