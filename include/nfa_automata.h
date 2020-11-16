#ifndef NFA_AUTOMATA_H_
#define NFA_AUTOMATA_H_

#include <iostream>
#include <fstream>
#include <string>
#include "automata.h"
#include "transitions_nfa.h"

class Nfa : public Automata {
public:
  using Automata::Automata;
  Nfa(const std::string& buid_path_file);
  ~Nfa();

  bool CheckWord(const std::string& word);

  friend std::istream& operator>>(std::istream& is, Nfa& nfa);
};

#endif