#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <map>
#include <string>

namespace politocean::constants {
namespace sensors {
namespace id {
inline static const std::string kTemperature = "temperature";
}
namespace value {
static const char kTemperature = 1;
}
const std::map<std::string, char> mapIDToValue{
    {id::kTemperature, value::kTemperature}};

const std::map<char, std::string> mapValueToID{
    {value::kTemperature, id::kTemperature}};
} // namespace sensors
namespace topics {
inline static const std::string kCommandsTopic = "commands/";
inline static const std::string kAxesTopic = "axes/";
} // namespace topics
namespace commands {
namespace id {
inline static const std::string kToggleThrusters = "TOGGLE THRUSTERS";
inline static const std::string kCloseNipper = "CLOSE NIPPER";
inline static const std::string kStopNipper = "STOP NIPPER";
inline static const std::string kOpenNipper = "OPEN NIPPER";
inline static const std::string kToggleArm = "TOGGLE ARM";
inline static const std::string kSwitchCamera = "SWITCH CAMERA";
inline static const std::string kTogglePower = "TOGGLE POWER";
inline static const std::string kDecreaseSpeed = "DECREASE SPEED";
inline static const std::string kIncreaseSpeed = "INCREASE SPEED";
inline static const std::string kMoveShoulderUp = "MOVE SHOULDER UP";
inline static const std::string kStopShoulder = "STOP SHOULDER";
inline static const std::string kMoveShoulderDown = "MOVE SHOULDER DOWN";
inline static const std::string kRotateWristCCW = "ROTATE WRIST CCW";
inline static const std::string kStopWrist = "STOP WRIST";
inline static const std::string kRotateWristCW = "ROTATE WRIST CW";
} // namespace id

namespace value {
static const uint8_t kToggleThrusters = 1;
static const uint8_t kCloseNipper = 2;
static const uint8_t kStopNipper = 3;
static const uint8_t kOpenNipper = 4;
static const uint8_t kToggleArm = 5;
static const uint8_t kSwitchCamera = 6;
static const uint8_t kTogglePower = 7;
static const uint8_t kDecreaseSpeed = 8;
static const uint8_t kIncreaseSpeed = 9;
static const uint8_t kMoveShoulderUp = 10;
static const uint8_t kStopShoulder = 11;
static const uint8_t kMoveShoulderDown = 12;
static const uint8_t kRotateWristCCW = 13;
static const uint8_t kStopWrist = 14;
static const uint8_t kRotateWristCW = 15;
} // namespace value

static const std::map<std::string, uint8_t> mapIDToValue{
    {id::kToggleThrusters, value::kToggleThrusters},
    {id::kCloseNipper, value::kCloseNipper},
    {id::kStopNipper, value::kStopNipper},
    {id::kOpenNipper, value::kOpenNipper},
    {id::kToggleArm, value::kToggleArm},
    {id::kSwitchCamera, value::kSwitchCamera},
    {id::kTogglePower, value::kTogglePower},
    {id::kDecreaseSpeed, value::kDecreaseSpeed},
    {id::kIncreaseSpeed, value::kIncreaseSpeed},
    {id::kMoveShoulderUp, value::kMoveShoulderUp},
    {id::kStopShoulder, value::kStopShoulder},
    {id::kMoveShoulderDown, value::kMoveShoulderDown},
    {id::kRotateWristCCW, value::kRotateWristCCW},
    {id::kStopWrist, value::kStopWrist},
    {id::kRotateWristCW, value::kRotateWristCW}};
} // namespace commands
} // namespace politocean::constants

#endif // CONSTANTS_H