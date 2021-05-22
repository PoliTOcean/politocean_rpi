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

namespace actions {
  static const uint8_t TOGGLE_THRUSTERS = 1;
  static const uint8_t CLOSE_NIPPER = 2;
  static const uint8_t STOP_NIPPER = 3;
  static const uint8_t OPEN_NIPPER = 4;
  static const uint8_t TOGGLE_ARM = 5;
  static const uint8_t SWITCH_CAMERA = 6;
  static const uint8_t TOGGLE_POWER = 7;
  static const uint8_t DECREASE_SPEED = 8;
  static const uint8_t INCREASE_SPEED = 9;
  static const uint8_t MOVE_SHOULDER_UP = 10;
  static const uint8_t STOP_SHOULDER = 11;
  static const uint8_t MOVE_SHOULDER_DOWN = 12;
  static const uint8_t ROTATE_WRIST_CCW = 13;
  static const uint8_t STOP_WRIST = 14;
  static const uint8_t ROTATE_WRIST_CW = 15;

  const std::map<std::string, uint8_t> actionToID {
    {"TOGGLE THRUSTERS", TOGGLE_THRUSTERS},
    {"CLOSE NIPPER", CLOSE_NIPPER},
    {"STOP NIPPER", STOP_NIPPER},
    {"OPEN NIPPER", OPEN_NIPPER},
    {"TOGGLE ARM", TOGGLE_ARM},
    {"SWITCH CAMERA", SWITCH_CAMERA},
    {"TOGGLE POWER", TOGGLE_POWER},
    {"DECREASE SPEED", DECREASE_SPEED},
    {"INCREASE SPEED", INCREASE_SPEED},
    {"MOVE SHOULDER UP", MOVE_SHOULDER_UP},
    {"STOP SHOULDER", STOP_SHOULDER},
    {"MOVE SHOULDER DOWN", MOVE_SHOULDER_DOWN},
    {"ROTATE WRIST CCW", ROTATE_WRIST_CCW},
    {"STOP WRIST", STOP_WRIST},
    {"ROTATE WRIST CW", ROTATE_WRIST_CW}
  }; 
} // namespace actions

#endif // COMMAND_H