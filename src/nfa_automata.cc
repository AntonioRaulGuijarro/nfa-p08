#include "../include/nfa_automata.h"

Nfa::Nfa(const std::string& buid_path_file) : Automata() {
  transitions_ = new TransitionsNfa;
  std::fstream build_file(buid_path_file, std::ios::in);
  if (!build_file.is_open()) throw "ARCHIVO NO ENCONTRADO";
  build_file >> *this;
}

Nfa::~Nfa() {}

bool Nfa::CheckWord(const std::string& word) {
  std::set<State> match_states;
  std::set<State> match_eps_states;
  std::set<State> aux_states;
  match_eps_states = transitions_->find(initial_, EPSILON);

  for (char symbol : word) {
    if (alphabet_.find(symbol) == alphabet_.end()) return false;
    match_states.clear();
    for (auto it = match_eps_states.begin(); it != match_eps_states.end();
         it++) {
      aux_states = transitions_->find(*it, symbol);
      match_states.insert(aux_states.begin(), aux_states.end());
    }
    match_eps_states.clear();
    for (auto it = match_states.begin(); it != match_states.end(); it++) {
      aux_states = transitions_->find(*it, EPSILON);
      match_eps_states.insert(aux_states.begin(), aux_states.end());
    }
  }
  std::set<State> intersection;
  std::set_intersection(match_states.begin(), match_states.end(),
                        finals_.begin(), finals_.end(),
                        std::inserter(intersection, intersection.begin()));

  return intersection.size() != 0;
}

std::istream& operator>>(std::istream& is, Nfa& nfa) {
  int number_states, initial_state_id, current_id, number_transitions, to_state,
      counter = 0;
  char symbol;
  bool isFinal;

  is >> number_states;
  is >> initial_state_id;
  nfa.BuildStates(number_states);
  nfa.initial_ = State(initial_state_id);
  while (!is.eof()) {
    counter++;
    is >> current_id;
    is >> isFinal;
    is >> number_transitions;

    if (isFinal) nfa.finals_.insert(current_id);
    for (int i = 0; i < number_transitions; i++) {
      if (is.eof()) throw "MALA DECLARACIÓN DE CONSTRUCCIÓN";
      is >> symbol;
      is >> to_state;
      nfa.alphabet_.insert(symbol);
      nfa.transitions_->insert(
          std::make_pair(KeyTransition(current_id, symbol), State(to_state)));
    }
  }
  if (counter != number_states) throw "NÚMERO DE ESTADOS MAL ESTABLECIDOS";
  return is;
}