/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y algorítmia
 *
 * @file nfa_simulation_program.cc
 * @author Antonio Raúl Guijarro Contreras (alu0101100494@ull.edu.es)
 * @brief Desarrollo de la clase NfaSimulationProgram.
 * @version 0.1
 * @date 2020-11-16
 * @copyright Copyright (c) 2020
 */

#include "../include/nfa_simulation_program.h"

NfaSimulationProgram::~NfaSimulationProgram() {}

int NfaSimulationProgram::Run() {
  if (arg_.size() != 4) {
    ShowUsage();
  } else {
    try {
      Process();
    } catch (std::ios_base::failure& input_out_error) {
      std::cerr << input_out_error.what() << std::endl;
    } catch (AutomataException& automata_error) {
      std::cerr << automata_error.what() << std::endl;
    }
  }
  return 0;
}

void NfaSimulationProgram::Process() {
  std::string input_path_nfa = arg_[1];
  Automata* nfa = new Nfa(input_path_nfa);
  Modification(nfa);
  Analyse(nfa);
  delete nfa;
}

void NfaSimulationProgram::Modification(Automata*& nfa) {
  nfa->
}

void NfaSimulationProgram::Analyse(Automata*& nfa) {
  std::string input_path_words = arg_[2];
  std::string output_path_results = arg_[3];
  std::fstream input_words(input_path_words, std::ios::in);
  std::fstream output_result(output_path_results, std::ios::out);
  std::string line;

  if (!input_words.is_open() || !output_result.is_open())
    throw std::ios_base::failure("FALLO A LA HORA DE CARGAR ARCHIVOS");

  while (!input_words.eof()) {
    std::getline(input_words, line);
    output_result << line << " -- ";
    output_result << (nfa->CheckWord(line) ? "Si" : "No") << std::endl;
  }

  input_words.close();
  output_result.close();
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