#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "politocean/mqtt.h"
#include <string>

using namespace std;
using namespace politocean;

const string MQTT_ADDRESS{"tcp://localhost:1883"};
const string MQTT_ID{"mqtt_id"};

MQTTClient mqttClient(MQTT_ADDRESS, MQTT_ID);

void fn(const string &msg) {}

TEST_CASE("Connect to MQTT", "mqtt") {
  mqttClient.subscribeTo("hello", fn);
  mqttClient.connect();

  cout << "Press Enter to Continue";
  cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

  REQUIRE(true);
}

TEST_CASE("Disconnect to MQTT", "mqtt") {
  mqttClient.disconnect();

  cout << "Press Enter to Continue";
  cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

  REQUIRE(true);
}