#include "PasswordManager.h"
#include <filesystem>
#include <fstream>
#include <iostream>

std::string dbPath;
std::vector<pw> allCreds;

void PasswordManager::setDbPath() {
  std::cout << "Please give db path" << std::endl;
  std::getline(std::cin, dbPath);
  if (!std::filesystem::exists(dbPath)) {
    createNewDb();
  }
}

void PasswordManager::createNewDb() {
  std::ofstream passwordDb;
  passwordDb.open(dbPath);
  passwordDb << "New Database;Made by;APE";
}
pw PasswordManager::createCred() {
  std::string website, user, pwd;
  std::cout << "Enter Website" << std::endl;
  std::getline(std::cin, website);
  std::cout << "Enter Username" << std::endl;
  std::getline(std::cin, user);
  std::cout << "Enter password" << std::endl;
  std::getline(std::cin, pwd);
  std::pair<std::string, std::string> userPwd = {user, pwd};
  pw newCred = {website, userPwd};
  return newCred;
}

void PasswordManager::addToDb(pw newCred) {
  std::ofstream passwordDB;
  passwordDB.open(dbPath, std::ios::app);
  passwordDB << newCred.first << ";" << newCred.second.first << ";"
             << newCred.second.second << std::endl;
  passwordDB.close();
  return;
}

void PasswordManager::deleteCred(std::string website) {}

std::vector<pw> PasswordManager::readAllCreds() {
  std::ifstream passwordDb(dbPath);
  std::vector<pw> allCreds;
  std::string line;

  while (std::getline(passwordDb, line)) {
    std::stringstream ss(line);
    std::string website, user, pwd;

    if (std::getline(ss, website, ';') && std::getline(ss, user, ';') &&
        std::getline(ss, pwd, ';')) {
      pw currentCred = {website, {user, pwd}};
      allCreds.push_back(currentCred);
    }
  }

  return allCreds;
}

void PasswordManager::printAllCreds() {
  std::vector<pw> allCreds = readAllCreds();
  for (auto pws : allCreds) {
    std::cout << pws.first << "  " << pws.second.first << "  "
              << pws.second.second << std::endl;
  }
}

std::string PasswordManager::returnDbPath() { return dbPath; }
