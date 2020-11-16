#include "../include/nfa_automata.h"

Nfa::Nfa(const std::string& buid_path_file) {
  std::fstream build_file(buid_path_file, std::ios::in);
  if (!build_file.is_open()) throw "ARCHIVO NO ENCONTRADO";
  build_file >> *this;
}

Nfa::~Nfa() {}

bool Nfa::CheckWord(const std::string& word) {}

std::istream& operator>>(std::istream& is, const Nfa& nfa) {
  int number_states, initial_state_id, current_id, number_transitions, to_state;
  char symbol;
  bool isFinal;

  is >> number_states;
  is >> initial_state_id;
  while (!is.eof()) {
    is >> current_id;
    is >> isFinal;
  }
}