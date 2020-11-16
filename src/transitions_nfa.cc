#include "../include/transitions_nfa.h"

TransitionsNfa::~TransitionsNfa() {}

std::set<State> TransitionsNfa::find(const State& state, char symbol) const {
  std::set<State> match_states;
  auto range = this->equal_range(KeyTransition(state, symbol));

  if (symbol == EPSILON) match_states.insert(state);
  if (range.first == this->end() && range.second == this->end() &&
      match_states.size() == 0)
    match_states.insert(State::NULL_STATE());
  else {
    for (auto it = range.first; it != range.second; ++it)
      match_states.insert(it->second);
  }

  return match_states;
}