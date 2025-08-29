#ifndef PASSWORD_GIVER_H
#define PASSWORD_GIVER_H

#include <iostream>
#include <utility>
#include <vector>

typedef std::pair<std::string, std::pair<std::string, std::string>> pw;

class PasswordGiver {
public:
  PasswordGiver(const std::string &dbPath);
  std::string returnPassword(const std::string &website);

private:
  std::string dbPath;
};

#endif // !PASSWORD_GIVER_H
