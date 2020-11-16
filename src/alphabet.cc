/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file alphabet.cc
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Desarrollo de la clase Alphabet
 * simbolos.
 * @version 0.1
 * @date 2020-11-03
 * @copyright Copyright (c) 2020
 */

#include "../include/alphabet.h"

void Alphabet::SetFromWord(const std::string& word) {
  for (char symbol : word) insert(symbol);
}

std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  os << "Σ: ";
  for (const auto& symbol : alphabet) os << symbol << ", ";
  return os;
}