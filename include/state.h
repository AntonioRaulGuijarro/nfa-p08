/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file state.h
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Cabecera de la clase State. Representa a un estado, es deicir, una clase
 * que encapsula una identificación.
 * @version 0.1
 * @date 2020-11-03
 * @copyright Copyright (c) 2020
 */

#ifndef STATE_H_
#define STATE_H_

#include <iostream>

class State {
 public:
  State();
  State(int id);
  ~State();

  int Get() const;

  friend std::ostream& operator<<(std::ostream& os, const State& state);
  friend bool operator==(const State& state_a, const State& state_b);
  friend bool operator<(const State& state_a, const State& state_b);
  friend bool operator<(const State& state_a, int id_b_state);
  State operator=(const State& state);

 public:
  static const State NULL_STATE;

 private:
  int id_;
};

#endif