/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file transitions.h
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Cabecera de la clase Tranitions. Se extienede de un mapa multiple
 * desordenado con clave State y valor char. Su objetivo es seguir el
 * comportamiento de la función de transición de un automata.
 * @version 1.1
 * @date 2020-11-03
 * @copyright Copyright (c) 2020
 */

#ifndef TRANSITIONS_H_
#define TRANSITIONS_H_

#include <iostream>
#include <unordered_map>
#include <utility>
#include <set>

#include "key_transition.h"
#include "state.h"

typedef std::unordered_multimap<KeyTransition, State, HashKeyTransition> TransitionMap;

class Transitions : public TransitionMap {
 public:
  Transitions();
  virtual ~Transitions();

  virtual std::set<State> find(const State& state, char symbol) const = 0;

  friend std::ostream& operator<<(std::ostream& os,
                                  const Transitions& transitions);
};

const char EPSILON = '~';

#endif