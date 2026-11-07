#include <string>
#include <vector>
#include "account.h"
#include "game.h"
#ifndef USER_H
#define USER_H

class User : public Account {
public:

    // User constructor
    User(const std::string& username, const std::string& type, double credit = 0.0);

    void sellGame(const std::string& name, double price);
    void buyGame(const std::string& game, const std::string& seller);

}; 

#endif