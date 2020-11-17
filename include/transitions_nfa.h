/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file transitions_nfa.h
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Cabecera de la clase extención de Tranitions. Clase capaz de
 * interpretar las trasiciones de un NFA.
 * @version 0.1
 * @date 2020-11-16
 * @copyright Copyright (c) 2020
 */

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