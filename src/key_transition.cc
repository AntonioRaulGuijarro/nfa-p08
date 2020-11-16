/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file key_transition.cc
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Desarrollo de los operadores y función hash de las clases
 * Keytransition y HashKeyTransition. simbolos.
 * @version 0.1
 * @date 2020-11-03
 * @copyright Copyright (c) 2020
 */

#include "../include/key_transition.h"

KeyTransition KeyTransition::operator=(const KeyTransition& key) {
  first = key.first;
  second = key.second;
  return *this;
}

bool operator<(const KeyTransition& key_a, const KeyTransition& key_b) {
  if (key_a.first.Get() == key_b.first.Get())
    return key_a.second < key_b.second;
  return key_a.first.Get() < key_b.first.Get();
}

bool operator==(const KeyTransition& key_a, const KeyTransition& key_b) {
  return key_a.first.Get() == key_b.first.Get() && key_a.second == key_b.second;
}

size_t HashKeyTransition::operator()(const KeyTransition& key) const {
  return key.second / ~key.first.Get();
}