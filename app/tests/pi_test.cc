#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "pi.h"
#include "politocean/pi/pinout.h"

#include <string>

using namespace std;
using namespace politocean::pi;

Pi pi;

TEST_CASE("Create Pi", "pi") {
  map<string, pin_t> pinout;

  pinout = pi.getPinout();

  REQUIRE(pinout[Pinout::NIPPER_DIR] == 23);
  REQUIRE(pinout[Pinout::NIPPER_PWM] == 24);
  REQUIRE(pinout[Pinout::SHOULDER_EN] == 22);
  REQUIRE(pinout[Pinout::SHOULDER_DIR] == 27);
  REQUIRE(pinout[Pinout::SHOULDER_STEP] == 17);
  REQUIRE(pinout[Pinout::WRIST_EN] == 21);
  REQUIRE(pinout[Pinout::WRIST_DIR] == 20);
  REQUIRE(pinout[Pinout::WRIST_STEP] == 16);
  REQUIRE(pinout[Pinout::CAMERA_EN] == 5);
  REQUIRE(pinout[Pinout::CAMERA_DIR] == 6);
  REQUIRE(pinout[Pinout::CAMERA_STEP] == 13);
  REQUIRE(pinout[Pinout::LIGHTS_DIR] == 0);
  REQUIRE(pinout[Pinout::LIGHTS_PWM] == 0);
  REQUIRE(pinout[Pinout::POWER] == 18);
}