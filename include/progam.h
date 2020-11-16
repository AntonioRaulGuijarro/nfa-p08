/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file program.h
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Cabecera de la clase Program. Interfaz de un programa.
 * @version 0.1
 * @date 2020-11-03
 * @copyright Copyright (c) 2020
 */


#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <vector>
#include <string>

class Program {
 public:
  Program(int argc, char const *argv[]);
  virtual ~Program();

  virtual int Run() = 0;
  virtual void ShowUsage() const = 0;

 protected: 
  std::vector<std::string> arg_;

 protected:
  std::vector<std::string> ParseArgv(int argc, char const *argv[]);
};

#endif