#include <functional>
#include <map>

#include "mqtt.h"
#include "mqtt/async_client.h"
#include "spdlog/spdlog.h"

using namespace politocean;

void MQTTClient::callback::reconnect() {
  std::this_thread::sleep_for(std::chrono::milliseconds(2500));
  try {
    cli_.connect(connOpts_, nullptr, *this);
  } catch (const mqtt::exception &exc) {
    spdlog::critical("Error: {}", exc.what());
  }
}

void MQTTClient::callback::on_failure(const mqtt::token &tok) {
  spdlog::error("Connection attempt failed");
  if (++nretry_ > N_RETRY_ATTEMPTS)
    exit(1);
  reconnect();
}

void MQTTClient::callback::on_success(const mqtt::token &tok) {}

void MQTTClient::callback::connected(const std::string &cause) {
  spdlog::info("Connection success");

  for (auto f : functions_) {
    spdlog::info("Subscribed to {}", f.first);
    cli_.subscribe(f.first, QOS);
  }
}

void MQTTClient::callback::connection_lost(const std::string &cause) {
  spdlog::error("Connection lost");
  spdlog::info("Reconnecting...");
  nretry_ = 0;
  reconnect();
}

void MQTTClient::callback::message_arrived(mqtt::const_message_ptr msg) {
  std::string topic = msg->get_topic();
  spdlog::info("Message arrived on topic {}", topic);

  for (auto f : functions_) {
    if (topic == f.first) {
      return (f.second)(msg->get_payload_str());
    }
  }
}

void MQTTClient::callback::delivery_complete(mqtt::delivery_token_ptr token) {}

MQTTClient::callback::callback(
    mqtt::async_client &cli, mqtt::connect_options &connOpts,
    std::map<std::string, std::function<void(const std::string &)>> &functions)
    : nretry_(0), cli_(cli), connOpts_(connOpts), functions_(functions) {}

MQTTClient::MQTTClient(const std::string &address, const std::string &id)
    : _mqtt(address, id), _connOpts(), _cb(_mqtt, _connOpts, _callbacks) {
  _connOpts.set_clean_session(false);
  _mqtt.set_callback(_cb);
}

void MQTTClient::subscribeTo(
    const std::string &topic,
    const std::function<void(const std::string &)> &fn) {
  _callbacks.insert(
      std::pair<std::string, std::function<void(const std::string &)>>(topic,
                                                                       fn));
}

void MQTTClient::unsubscribeTo(const std::string &topic) {
  _callbacks.erase(topic);
}

void MQTTClient::connect() { _mqtt.connect(); }
void MQTTClient::disconnect() { _mqtt.disconnect(); }