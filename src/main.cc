#include "../include/nfa_simulation_program.h"

int main(int argc, char const *argv[]) {
  Program* nfa_program = new NfaSimulationProgram(argc, argv);
  nfa_program->Run();
  delete nfa_program;
  return 0;
}
