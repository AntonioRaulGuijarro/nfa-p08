#include "../include/nfa_simulation_program.h"

NfaSimulationProgram::~NfaSimulationProgram() {}

int NfaSimulationProgram::Run() {
  if (arg_.size() != 4) {
    ShowUsage();
  } else {
    try {
      Process();
    } catch (const std::string& error) {
      std::cerr << error << std::endl;
    }
  }
  return 0;
}

void NfaSimulationProgram::Process() {
  std::string input_path_nfa = arg_[1];
  std::string input_path_words = arg_[2];
  std::string output_path_results = arg_[3];
  std::fstream input_words(input_path_words, std::ios::in);
  std::fstream output_result(output_path_results, std::ios::out);
  Automata* nfa;
  if (!input_words.is_open() || !output_result.is_open())
    throw "FALLO A LA HORA DE CARGAR O CREAR ARCHIVOS";
  
  nfa = new Nfa(input_path_nfa);
  std::cout << *nfa;
}

void NfaSimulationProgram::ShowUsage() const {
  std::cout
      << "Forma de uso: ./nfa_simulation input.nfa input.txt output.txt"
      << std::endl
      << "  * Un fichero de texto con extension´ .nfa en el que figura la "
         "especificacion de un NFA"
      << std::endl
      << "  * Un fichero de texto con extensión .txt en el que figura una "
         "serie de cadenas (una cadena por líınea) sobre el alfabeto NFA "
         "especificado en el fichero input.nfa."
      << std::endl
      << "  * Un fichero de texto de salida con extensión .txt en el que el "
         "programa ha de escribir las mismas cadenas del fichero de "
         "entrada seguidas de un texto -- Sí / No indicativo de la "
         "aceptacion (o no) de la cadena en cuestión. Este fichero debe "
         "ser sobreescrito por el programa en cada ejecucion."
      << std::endl;
}