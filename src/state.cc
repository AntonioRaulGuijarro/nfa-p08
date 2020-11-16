/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file program.cc
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Desarrollo de la clase State
 * @version 0.1
 * @date 2020-11-03
 * @copyright Copyright (c) 2020
 */

#include "../include/state.h"

State::State() { id_ = -1; }

State::State(int id) { id_ = id; }

State::~State() {}

int State::Get() const { return id_; }

std::ostream& operator<<(std::ostream& os, const State& state) {
  os << "q" << state.Get();
  return os;
}

bool operator<(const State& state_a, const State& state_b) {
  return state_a.Get() < state_b.Get();
}

bool operator<(const State& state_a, int id_b_state) {
  return state_a.Get() < id_b_state;
}

State State::operator=(const State& state) {
  id_ = state.Get();
  return *this;
}