#ifndef NFA_SIMULATION_PROGRAM_H_
#define NFA_SIMULATION_PROGRAM_H_

#include "program.h"
#include "automata.h"
#include "nfa_automata.h"


class NfaSimulationProgram : public Program {
public:
  using Program::Program;
  ~NfaSimulationProgram();

  int Run();
  void Process();
  void Analyse(Automata*& nfa);
  void ShowUsage() const;
};

#endif