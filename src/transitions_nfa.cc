/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file transitions_nfa.cc
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Desarrollo de la clase transitions_nfa.
 * @version 0.1
 * @date 2020-11-16
 * @copyright Copyright (c) 2020
 */

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