#ifndef COMPONENT_H
#define COMPONENT_H

#include "stateful.h"

#include <string>

using namespace std;

namespace politocean::component {
enum class State { Enabled, Disabled };

class Component : public virtual Stateful<State> {
  string _id;
  State _state;

public:
  Component(string id) : _id(id), _state(State::Disabled){};

  State getState() const { return _state; };
  void setState(const State &state) { _state = state; };

  const string &getID() const { return _id; };
};
} // namespace politocean::component

#endif // COMPONENT_H