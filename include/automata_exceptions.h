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