#pragma once

#include <iostream>
#include <utility>
#include <vector>

typedef std::pair<std::string, std::pair<std::string, std::string>> pw;

class PasswordCreator {
public:
  enum PasswordType {
    Alphabet = 1,
    AlphabetNumber = 2,
    AlphabetNumberSymbol = 3,
  };

    PasswordType passwordSecurity();
    std::string createPassword(PasswordType type);


};
