#include "../include/nfa_simulation_program.h"

int main(int argc, char const *argv[]) {
  int exit_return;
  Program* nfa_program = new NfaSimulationProgram(argc, argv);
  exit_return = nfa_program->Run();
  delete nfa_program;
  return exit_return;
}
