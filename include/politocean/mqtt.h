#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <functional>
#include <map>

#include "mqtt/async_client.h"

namespace politocean {

struct MQTTConfig {
  std::string id, address;
};

class MQTTClient {
  class callback : public virtual mqtt::callback,
                   public virtual mqtt::iaction_listener {
    int nretry_;

    mqtt::async_client &cli_;
    mqtt::connect_options &connOpts_;
    std::map<std::string, std::function<void(const std::string &)>> &functions_;

    const int QOS = 1;
    const int N_RETRY_ATTEMPTS = 5;
    const std::string AXIS_TOPIC = "axis";
    const std::string COMMAND_TOPIC = "command";

    void reconnect();

    void on_failure(const mqtt::token &tok) override;
    void on_success(const mqtt::token &tok) override;
    void connected(const std::string &cause) override;
    void connection_lost(const std::string &cause) override;
    void message_arrived(mqtt::const_message_ptr msg) override;
    void delivery_complete(mqtt::delivery_token_ptr token) override;

  public:
    callback(mqtt::async_client &cli, mqtt::connect_options &connOpts,
             std::map<std::string, std::function<void(const std::string &)>>
                 &functions);
  };

  mqtt::async_client _mqtt;
  mqtt::connect_options _connOpts;
  callback _cb;
  std::map<std::string, std::function<void(const std::string &)>> _callbacks;

public:
  MQTTClient(const std::string &address, const std::string &id);

  template <class T>
  void subscribeTo(const std::string &topic, void (T::*pf)(const std::string &),
                   T *obj) {
    _callbacks.insert(
        std::pair<std::string, std::function<void(const std::string &)>>(
            topic, (std::function<void(const std::string &)>)std::bind(
                       pf, obj, std::placeholders::_1)));
  }

  void subscribeTo(const std::string &topic,
                   std::function<void(const std::string &)> fn) {
    _callbacks.insert(
        std::pair<std::string, std::function<void(const std::string &)>>(topic,
                                                                         fn));
  }
  void unsubscribeTo(const std::string &topic);

  void connect();
  void disconnect();
};
} // namespace politocean

#endif // MQTT_CLIENT_H