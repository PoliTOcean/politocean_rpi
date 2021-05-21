#include "command.h"
#include "nlohmann/json.hpp"

#include <string>

using namespace std;
using namespace politocean;

Command::Command(const string &action, const string &component, int value)
    : _action(action), _component(component), _value(value) {}

Command Command::parse(const string &str) {
  nlohmann::json j = nlohmann::json::parse(str);

  string action, component;
  int value = 0;

  int size = j.size();

  if (size < 2 || size > 3) {
    throw ParsingException("Parsing error");
  }

  try {
    action = j["action"];
    component = j["component"];

    if (size == 3) {
      value = j["value"];
    }
  } catch (nlohmann::json::parse_error &ex) {
    throw ParsingException(ex.what());
  }

  return Command(action, component, value);
}

const std::string Command::stringify() {
  nlohmann::json j;

  j["action"] = _action;
  j["component"] = _component;
  j["value"] = _value;

  return j.dump();
}