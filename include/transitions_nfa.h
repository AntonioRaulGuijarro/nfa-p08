#ifndef TRANSITIONS_NFA_H_
#define TRANSITIONS_NFA_H_

#include <iostream>

#include "transitions.h"

class TransitionsNfa : public Transitions {
 public:
  using Transitions::Transitions;
  ~TransitionsNfa();
  std::set<State> find(const State& state, char symbol) const;
};

#endif