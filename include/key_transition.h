/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file key_transition.h
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Cabecera de la clase KeyTransition Y HashKeyTransition. KeyTransition
 * es una extención de std::pair<State, char> que facilitará la iterabilidad con
 * las clases de conjuntos de la STL. HashKeyTransition es la plantilla que
 * generará el hash a la clase KeyTransition.
 * @version 0.1
 * @date 2020-11-03
 * @copyright Copyright (c) 2020
 */

#ifndef KEY_TRANSITION_H_
#define KEY_TRANSITION_H_

#include <utility>

#include "state.h"

class KeyTransition : public std::pair<State, char> {
 public:
  using std::pair<State, char>::pair;
  KeyTransition(int id_state, char symbol);

  KeyTransition operator=(const KeyTransition& key);
  friend bool operator<(const KeyTransition& key_a, const KeyTransition& key_b);
  friend bool operator==(const KeyTransition& key_a,
                         const KeyTransition& key_b);
};

class HashKeyTransition {
 public:
  size_t operator()(const KeyTransition& key) const;
};

#endif
