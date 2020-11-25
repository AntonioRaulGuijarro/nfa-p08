/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file nfa_automata.h
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Cabecera de la clase Nfa. Se comporta como un Autómata no finito.
 * @version 0.1
 * @date 2020-11-16
 * @copyright Copyright (c) 2020
 */

#ifndef NFA_AUTOMATA_H_
#define NFA_AUTOMATA_H_

#include <iostream>
#include <fstream>
#include <string>
#include "automata.h"
#include "transitions_nfa.h"

class Nfa : public Automata {
public:
  using Automata::Automata;
  Nfa(const std::string& buid_path_file);
  ~Nfa();

  bool CheckWord(const std::string& word);
  void Modification();

  friend std::istream& operator>>(std::istream& is, Nfa& nfa);
};

#endif