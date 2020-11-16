#include "../include/nfa_automata.h"

Nfa::Nfa(const std::string& buid_path_file) {
  transitions_ = new TransitionsNfa;
  std::fstream build_file(buid_path_file, std::ios::in);
  if (!build_file.is_open()) throw "ARCHIVO NO ENCONTRADO";
  build_file >> *this;
}

Nfa::~Nfa() {}

bool Nfa::CheckWord(const std::string& word) {}

std::istream& operator>>(std::istream& is, Nfa& nfa) {
  int number_states, initial_state_id, current_id, number_transitions, to_state;
  char symbol;
  bool isFinal;

  is >> number_states;
  is >> initial_state_id;
  nfa.BuildStates(number_states);
  nfa.initial_ = State(initial_state_id);
  while (!is.eof()) {
    is >> current_id;
    is >> isFinal;
    is >> number_transitions;
    if (isFinal) nfa.finals_.insert(current_id);
    for (int i = 0; i < number_transitions; i++) {
      if (is.eof()) throw "MALA DECLARACIÓN DE CONSTRUCCIÓN";
      is >> symbol;
      is >> to_state;
      nfa.alphabet_.insert(symbol);
      nfa.transitions_->insert(std::make_pair(KeyTransition(current_id, symbol), State(to_state)));
    }
  }
}