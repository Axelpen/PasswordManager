#include "PasswordCreator.h"
#include <string>




PasswordCreator::PasswordType PasswordCreator::passwordSecurity() {
  PasswordType type;
  std::string test;
  std::cout << "Wie stark soll dein Password sein?" << std::endl;
  std::cout << "1) Buchstaben" << std::endl;
  std::cout << "2) Buchstaben und Zahlen" << std::endl;
  std::cout << "3) Buchstaben, Zahlen und Symbole" << std::endl;
  std::getline(std::cin, test);
  switch (std::stoi(test)) {
  case (1):
    type = Alphabet;
    break;
  case (2):
    type = AlphabetNumber;
    break;
  case (3):
    type = AlphabetNumberSymbol;
    break;
  default:
    std::cout << "du noob das war ne falsche nummer" << std::endl;
    std::cout << "explodiere pc in...";
    break;
  }
  return type;
}

std::string PasswordCreator::createPassword(PasswordType type){
  switch (type) {
    case(Alphabet):
      break;
    default:
        
      break;
  }
}
