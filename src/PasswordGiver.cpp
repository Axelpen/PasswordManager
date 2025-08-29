#include "PasswordGiver.h"

#include <fstream>
#include <sstream>


PasswordGiver::PasswordGiver(const std::string& path) : dbPath(path) {}

std::string PasswordGiver::returnPassword(const std::string& website) 
{
    std::ifstream stream(dbPath);
    std::string line;
    while (std::getline(stream, line)) {
        std::stringstream ss(line);
        std::string site, user, pwd;

        if (std::getline(ss, site, ';') &&
            std::getline(ss, user, ';') &&
            std::getline(ss, pwd, ';')) 
        {
            if (site == website) {
                return pwd;  // or format as desired
            }
        }
    }
    return "Not found";
}
