/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file program.cc
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Desarrollo de las funciones base de la clase Program.
 * @version 0.1
 * @date 2020-11-03
 * @copyright Copyright (c) 2020
 */

#include "../include/progam.h"

Program::Program(int argc, char const *argv[]) { arg_ = ParseArgv(argc, argv); }

Program::~Program() {}

std::vector<std::string> Program::ParseArgv(int argc, char const *argv[]) {
  std::vector<std::string> arguments;
  arguments.insert(arguments.end(), argv, argv + argc);
  return arguments;
}