#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "politocean/sensor.h"
#include <string>

using namespace std;
using namespace politocean;

const string SENSOR_ID{"temperature"};
const double SENSOR_VALUE = 10.5;

const string SENSOR_STRINGIFIED = "{\"temperature\":10.5}";
const string SENSOR_STRINGIFIED_TWO = "{\"temperature\":10.5,\"depth\":20.5}";

const string ONLY_ONE_SENSOR_ALLOWED = "Only one sensor allowed.\n";

Sensor sensor(SENSOR_ID, SENSOR_VALUE);

TEST_CASE("Create sensor", "sensor") {
  REQUIRE(sensor.getID() == SENSOR_ID);
  REQUIRE(sensor.getValue() == SENSOR_VALUE);
}

TEST_CASE("Stringify sensor", "sensor") {
  REQUIRE(sensor.stringify() == SENSOR_STRINGIFIED);
}

TEST_CASE("Parse sensor", "sensor") {
  Sensor parsed = Sensor::parse(SENSOR_STRINGIFIED);

  REQUIRE(parsed.getID() == SENSOR_ID);
  REQUIRE(parsed.getValue() == SENSOR_VALUE);
}

TEST_CASE("Parse more than one sensor", "sensor") {
  bool exception_caught = false;

  try {
    Sensor parsed = Sensor::parse(SENSOR_STRINGIFIED_TWO);
  } catch (const ParsingException &ex) {
    exception_caught = true;
    REQUIRE(ex.what() == ONLY_ONE_SENSOR_ALLOWED);
  }

  REQUIRE(exception_caught == true);
}