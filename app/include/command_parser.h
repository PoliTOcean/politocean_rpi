#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "mqtt/async_client.h"
#include "spdlog/spdlog.h"

namespace politocean {
class callback : public virtual mqtt::callback,
                 public virtual mqtt::iaction_listener

{
  int nretry_;
  mqtt::async_client &cli_;
  mqtt::connect_options &connOpts_;

  const int QOS = 1;
  const int N_RETRY_ATTEMPTS = 5;
  const std::string TOPIC = "hello";

public:
  void reconnect() {
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    try {
      cli_.connect(connOpts_, nullptr, *this);
    } catch (const mqtt::exception &exc) {
      spdlog::critical("Error: {}", exc.what());
    }
  }

  void on_failure(const mqtt::token &tok) override {
    spdlog::error("Connection attempt failed");
    if (++nretry_ > N_RETRY_ATTEMPTS)
      exit(1);
    reconnect();
  }

  void on_success(const mqtt::token &tok) override {}

  void connected(const std::string &cause) override {
    spdlog::info("Connection success");

    cli_.subscribe(TOPIC, QOS);
  }

  void connection_lost(const std::string &cause) override {
    spdlog::error("Connection lost");
    spdlog::info("Reconnecting...");
    nretry_ = 0;
    reconnect();
  }

  void message_arrived(mqtt::const_message_ptr msg) override {
    spdlog::info("Message arrived on topic {}", msg->get_topic());
  }

  void delivery_complete(mqtt::delivery_token_ptr token) override {}

public:
  callback(mqtt::async_client &cli, mqtt::connect_options &connOpts)
      : nretry_(0), cli_(cli), connOpts_(connOpts) {}
};
} // namespace politocean

#endif // COMMAND_PARSER_H