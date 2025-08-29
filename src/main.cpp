#include "PasswordManager.h"
#include "PasswordGiver.h"

int main (int argc, char *argv[]) {

  PasswordManager pwManager;
  pwManager.setDbPath();
  pwManager.printAllCreds();
  std::string dbPath = pwManager.returnDbPath();
  PasswordGiver pwGiver(dbPath);

  std::string command = argv[1];
  if(command == "a") 
  {
    pw newCred = pwManager.createCred();
    pwManager.addToDb(newCred);
  }
  else if (command== "c") {
    std::string website;
    std::cout << "Von welcher Website?" << std::endl;
    std::getline(std::cin, website);
    pwGiver.returnPassword( website);
  } 
        
  return 0;
} 
