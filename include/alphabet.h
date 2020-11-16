/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file alphabet.h
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Cabecera de la clase Alphabet. Se comporta como un conjunto de
 * simbolos.
 * @version 0.1
 * @date 2020-11-03
 * @copyright Copyright (c) 2020
 */

#ifndef ALPHABET_H_
#define ALPHABET_H_

#include <set>
#include <iostream>
#include <string>

class Alphabet : public std::set<char> {
 public:
  /**
   * @brief Añade al alfabeto los símbolos de word
   * @param word Palabra a conseguir el alfabeto.
   */
  void SetFromWord(const std::string& word);

  friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);
};

#endif