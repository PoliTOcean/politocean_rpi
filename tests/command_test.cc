#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "politocean/command.h"
#include <string>

using namespace std;
using namespace politocean;

const string COMMAND_ACTION{"move X"};
const string COMMAND_COMPONENT{"thrusters"};
const int COMMAND_VALUE = 1800;

const string COMMAND_STRINGIFIED =
    "{\"action\":\"move X\",\"component\":\"thrusters\",\"value\":1800}";

Command command(COMMAND_ACTION, COMMAND_COMPONENT, COMMAND_VALUE);

TEST_CASE("Create command", "command") {
  REQUIRE(command.getAction() == COMMAND_ACTION);
  REQUIRE(command.getComponent() == COMMAND_COMPONENT);
  REQUIRE(command.getValue() == COMMAND_VALUE);
}

TEST_CASE("Stringify command", "command") {
  REQUIRE(command.stringify() == COMMAND_STRINGIFIED);
}

TEST_CASE("Parse command", "command") {
  Command parsed = Command::parse(COMMAND_STRINGIFIED);

  REQUIRE(parsed.getAction() == COMMAND_ACTION);
  REQUIRE(parsed.getComponent() == COMMAND_COMPONENT);
  REQUIRE(parsed.getValue() == COMMAND_VALUE);
}