/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file main.cc
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief fichero principal para instanciar las abstracciones del programa.
 * @version 0.1
 * @date 2020-11-16
 * @copyright Copyright (c) 2020
 */

#include "../include/nfa_simulation_program.h"

int main(int argc, char const *argv[]) {
  int exit_return;
  Program* nfa_program = new NfaSimulationProgram(argc, argv);
  exit_return = nfa_program->Run();
  delete nfa_program;
  return exit_return;
}
