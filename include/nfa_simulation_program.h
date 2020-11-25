/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file nfa_simulation_program.h
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Cabecera de la clase extensión de Progam. Abstrae un programa que
 * genera un NFA y es capaz de leer un archivo de construcción del automata, un
 * fichero con un conjunto de palabras separadas por lineas para ser verificadas
 * por él y el fichero para exportar los resultados del análisis.
 * @version 0.1
 * @date 2020-11-16
 * @copyright Copyright (c) 2020
 */

#ifndef NFA_SIMULATION_PROGRAM_H_
#define NFA_SIMULATION_PROGRAM_H_

#include "automata.h"
#include "nfa_automata.h"
#include "program.h"

class NfaSimulationProgram : public Program {
 public:
  using Program::Program;
  ~NfaSimulationProgram();

  int Run();
  void Process();
  void Analyse(Automata*& nfa);
  void Modification(Automata*& nfa);
  void ShowUsage() const;
};

#endif