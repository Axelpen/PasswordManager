#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

#include <iostream>
#include <utility>
#include <vector>

typedef std::pair<std::string,std::pair<std::string,std::string>> pw;

class PasswordManager{
  public:
    void setDbPath();
    pw createCred();
    void addToDb(pw newCred);
    void deleteCred(std::string website);
    pw editCredentials(std::string website);
    void createNewDb();
    std::vector<pw> readAllCreds();
    void printAllCreds();
    std::string returnDbPath();
    std::string generatePassword();
    
};

#endif // !PASSWORD_MANAGER_H
