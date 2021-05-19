#include "command_parser.h"
#include "mqtt/async_client.h"
#include <cctype>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <thread>

const std::string SERVER_ADDRESS("tcp://localhost:1883");
const std::string CLIENT_ID("paho_cpp_async_subcribe");
const std::string TOPIC("hello");

const int QOS = 1;
const int N_RETRY_ATTEMPTS = 5;

/////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
  // A subscriber often wants the server to remember its messages when its
  // disconnected. In that case, it needs a unique ClientID and a
  // non-clean session.

  mqtt::async_client cli(SERVER_ADDRESS, CLIENT_ID);

  mqtt::connect_options connOpts;
  connOpts.set_clean_session(false);

  // Install the callback(s) before connecting.
  callback cb(cli, connOpts);
  cli.set_callback(cb);

  // Start the connection.
  // When completed, the callback will subscribe to topic.

  try {
    std::cout << "Connecting to the MQTT server..." << std::flush;
    cli.connect(connOpts, nullptr, cb);
  } catch (const mqtt::exception &exc) {
    std::cerr << "\nERROR: Unable to connect to MQTT server: '"
              << SERVER_ADDRESS << "'" << exc << std::endl;
    return 1;
  }

  // Just block till user tells us to quit.

  while (std::tolower(std::cin.get()) != 'q')
    ;

  // Disconnect

  try {
    std::cout << "\nDisconnecting from the MQTT server..." << std::flush;
    cli.disconnect()->wait();
    std::cout << "OK" << std::endl;
  } catch (const mqtt::exception &exc) {
    std::cerr << exc << std::endl;
    return 1;
  }

  return 0;
}
