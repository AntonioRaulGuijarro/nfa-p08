/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file automata.cc
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Desarrollo de las funciones base de la case Automata.
 * simbolos.
 * @version 0.1
 * @date 2020-11-03
 * @copyright Copyright (c) 2020
 */

#include "../include/automata.h"

Automata::Automata() {}

Automata::Automata(const std::set<State>& states, const Alphabet& alphabet,
                   State& initial, const std::set<State>& finals,
                   Transitions*& transitions) {
  states_ = states;
  alphabet_ = alphabet;
  initial_ = initial;
  finals_ = finals;
  transitions_ = transitions;
}

Automata::~Automata() { delete transitions_; }

void Automata::BuildStates(int number_states) {
  for (int i = 0; i < number_states; i++) states_.insert(i);
}

std::ostream& operator<<(std::ostream& os, const Automata& automata) {
  os << automata.alphabet_ << std::endl;
  os << "Q: ";
  for (const auto& state : automata.states_) os << state << ", ";
  os << std::endl;
  os << "s: " << automata.initial_ << std::endl;
  os << "F: ";
  for (const auto& state : automata.finals_) os << state << ", ";
  os << std::endl;
  os << *automata.transitions_;
  return os;
}