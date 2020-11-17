/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file automata_exceptions.cc
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Cabeceras de las clases que componen las excepciones de un Autómata.
 * @version 0.1
 * @date 2020-11-16
 * @copyright Copyright (c) 2020
 */

#ifndef AUTOMATA_EXCEPTIONS_H_
#define AUTOMATA_EXCEPTIONS_H_

#include <exception>

class AutomataException : public std::exception {};

class ConstructionException : public AutomataException {
 public:
  virtual const char* what() const throw() {
    return "MALA CONSTRUCCIÓN DEL AUTÓMATA";
  }
};

class InitialStateNotFoundException : public ConstructionException {
 public:
  virtual const char* what() const throw() {
    return "ESTADO INICIAL INEXISTENTE";
  }
};

class InsufficientStatesException : public ConstructionException {
public:
 virtual const char* what() const throw() {
   return "NÚMERO DE ESTADOS MAL ESTABLECIDOS";
 }
};

class StateNotDeclaredException : public ConstructionException {
public:
 virtual const char* what() const throw() {
   return "ESTADO FUERA DEL CONJUNTO DE ESTADOS";
 }
};

#endif