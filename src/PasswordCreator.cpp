#include "PasswordCreator.h"
#include <random>
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

std::string PasswordCreator::createPassword(PasswordType type) {
    const std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string numbers = "0123456789";
    const std::string symbols = "!@#$%^&*()-_=+[]{}<>?/|";

    std::string charset;

    switch (type) {
        case Alphabet:
            charset = letters;
            break;
        case AlphabetNumber:
            charset = letters + numbers;
            break;
        case AlphabetNumberSymbol:
            charset = letters + numbers + symbols;
            break;
        default:
            std::cerr << "Invalid password type selected." << std::endl;
            return "";
    }

    const int passwordLength = 12; // or ask the user for length
    std::string password;
    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr))); // seed
    std::uniform_int_distribution<> dist(0, static_cast<int>(charset.size() - 1));

    for (int i = 0; i < passwordLength; ++i) {
        password += charset[dist(rng)];
    }

    return password;
}
