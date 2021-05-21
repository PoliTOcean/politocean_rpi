#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "politocean/pi/pinout.h"
#include "politocean/pi/stepper.h"

#include <iostream>
#include <limits>
#include <string>

using namespace std;
using namespace politocean::pi;

const pin_t STEPPER_EN = 22;
const pin_t STEPPER_DIR_PIN = 27;
const pin_t STEPPER_STEP = 17;
const Direction STEPPER_DIR = Direction::CCW;
const uint8_t STEPPER_SPEED = 160;

Stepper stepper({STEPPER_EN, STEPPER_DIR_PIN, STEPPER_STEP});

TEST_CASE("Enable stepper", "stepper") {
  stepper.enable();

  cout << "Press Enter to Continue";
  cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

  REQUIRE(true);
}

TEST_CASE("Start stepping", "stepper") {
  stepper.step(Direction::CCW);

  cout << "Press Enter to Continue";
  cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

  REQUIRE(true);
}

TEST_CASE("Stop stepping", "stepper") {
  stepper.stop();

  cout << "Press Enter to Continue";
  cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

  REQUIRE(true);
}

TEST_CASE("Disable stepper", "stepper") {
  stepper.disable();

  cout << "Press Enter to Continue";
  cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

  REQUIRE(true);
}
