#ifndef COMPONENT_H
#define COMPONENT_H

#include "identifiable.h"
#include "stateful.h"

#include <string>

using namespace std;

namespace politocean::component {
enum class State { Disabled, Enabled };

class Component : public virtual Stateful<State>, public virtual Identifiable {
  string _id;
  State _state;

public:
  Component(string id) : _id(id), _state(State::Disabled){};

  inline State getState() const { return _state; };
  inline void setState(const State &state) { _state = state; };

  inline const string &getID() const { return _id; };
};
} // namespace politocean::component

#endif // COMPONENT_H