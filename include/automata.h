/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file automata.h
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Cabecera de la clase Automata. Interfaz de cualquier automata.
 * @version 0.1
 * @date 2020-11-03
 * @copyright Copyright (c) 2020
 */

#ifndef AUTOMATA_H_
#define AUTOMATA_H_

#include <set>

#include "alphabet.h"
#include "state.h"
#include "transitions.h"

class Automata {
 public:
  Automata();
  Automata(const std::set<State>& states, const Alphabet& alphabet,
           State& initial, const std::set<State>& finals,
          Transitions*& transitions);
  virtual ~Automata();

  /**
   * @brief Comprueba si una palabra pertenece al automata
   * @param word Palabra a comprobar
   * @return true Si pertenece al automata
   * @return false Si no pertenece al automata
   */
  virtual bool CheckWord(const std::string& word) = 0;
  /**
   * @brief Construye los estados en base al número de estados
   * @param number_states número de estados
   */
  void BuildStates(int number_states);

  friend std::ostream& operator<<(std::ostream& os, const Automata& automata);

 protected:
  Alphabet alphabet_;
  State initial_;
  std::set<State> states_;
  std::set<State> finals_;
  Transitions* transitions_;
};

#endif