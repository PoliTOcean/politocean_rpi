#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "politocean/component.h"
#include <string>

using namespace std;
using namespace politocean::component;

const string COMPONENT_ID{"thruster"};
const State COMPONENT_STATE = State::Disabled;
const State COMPONENT_STATE_NEW = State::Enabled;

Component component(COMPONENT_ID);

TEST_CASE("Create component", "component") {
  REQUIRE(component.getID() == COMPONENT_ID);
  REQUIRE(component.getState() == COMPONENT_STATE);
}

TEST_CASE("Set component state", "component") {
  component.setState(COMPONENT_STATE_NEW);

  REQUIRE(component.getState() == COMPONENT_STATE_NEW);
}