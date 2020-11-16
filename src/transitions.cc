/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file transitions.cc
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Desarrollo de las funciones base de la clase Transitions.
 * @version 0.1
 * @date 2020-11-03
 * @copyright Copyright (c) 2020
 */

#include "../include/transitions.h"

Transitions::Transitions() {}

Transitions::~Transitions() {}

std::ostream& operator<<(std::ostream& os, const Transitions& transitions) {
  for (const auto& key_value : transitions) {
    os << key_value.first.first << " - " << key_value.first.second << " -> "
       << key_value.second << std::endl;
  }
  return os;
}