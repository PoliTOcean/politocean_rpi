#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "politocean/pi/dcmotor.h"
#include "politocean/pi/pinout.h"
#include <iostream>
#include <string>

using namespace std;
using namespace politocean::pi;

const pin_t DCMOTOR_DIR_PIN = 23;
const pin_t DCMOTOR_PWM = 24;
const Direction DCMOTOR_DIR = Direction::CCW;
const uint8_t DCMOTOR_SPEED = 160;

DCMotor dcmotor({DCMOTOR_DIR_PIN, DCMOTOR_PWM});

TEST_CASE("Start PWM", "dcmotor") {
  dcmotor.run(DCMOTOR_DIR, DCMOTOR_SPEED);

  cout << "Press Enter to Continue";
  cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

  REQUIRE(true);
}

TEST_CASE("Stop PWM", "dcmotor") {
  dcmotor.stop();

  cout << "Press Enter to Continue";
  cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

  REQUIRE(true);
}
