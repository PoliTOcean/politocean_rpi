#include <functional>
#include <map>
#include <string>

#include "mqtt.h"
#include "mqtt/async_client.h"
#include "spdlog/spdlog.h"

using namespace politocean;

void MQTTClient::callback::reconnect() {
  std::this_thread::sleep_for(std::chrono::milliseconds(2500));
  try {
    cli_.connect(connOpts_, nullptr, *this);
  } catch (const mqtt::exception &exc) {
    spdlog::critical("[MQTT] Error: {}", exc.what());
  }
}

void MQTTClient::callback::on_failure(const mqtt::token &tok) {
  spdlog::error("[MQTT] Connection attempt failed");
  if (++nretry_ > N_RETRY_ATTEMPTS)
    exit(1);
  reconnect();
}

void MQTTClient::callback::on_success(const mqtt::token &tok) {}

void MQTTClient::callback::connected(const std::string &cause) {
  spdlog::info("[MQTT] Connection success");

  for (auto f : functions_) {
    spdlog::debug("[MQTT] Subscribed to {}", f.first);
    cli_.subscribe(f.first, QOS);
  }
}

void MQTTClient::callback::connection_lost(const std::string &cause) {
  spdlog::error("[MQTT] Connection lost");
  spdlog::info("[MQTT] Reconnecting...");
  nretry_ = 0;
  reconnect();
}

void MQTTClient::callback::message_arrived(mqtt::const_message_ptr msg) {
  std::string topic = msg->get_topic();
  spdlog::debug("[MQTT] Message arrived on topic {}", topic);

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
  _connOpts.set_keep_alive_interval(0);
  _mqtt.set_callback(_cb);
  spdlog::debug("[MQTT] Connected to {} with id {}", address, id);
}

void MQTTClient::unsubscribeTo(const std::string &topic) {
  _callbacks.erase(topic);
}

void MQTTClient::connect() { _mqtt.connect(); }
void MQTTClient::disconnect() { _mqtt.disconnect(); }