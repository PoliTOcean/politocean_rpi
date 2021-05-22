#ifndef COMPONENT_H
#define COMPONENT_H

#include "identifiable.h"
#include "stateful.h"

#include <string>

namespace politocean::component {
enum class State { Disabled, Enabled };

class Component : public virtual Stateful<State>, public virtual Identifiable {
  std::string _id;
  State _state;

public:
  Component(std::string id) : _id(id), _state(State::Disabled){};

  inline State getState() const { return _state; };
  inline void setState(const State &state) { _state = state; };

  inline const std::string &getID() const { return _id; };
};
} // namespace politocean::component

#endif // COMPONENT_H