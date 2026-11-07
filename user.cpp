#include <string>
#include <vector> 
#include <iostream>
#include "account.h"
#include "game.h"
#include "user.h"

// class user : public Account {
// protected:
//     std::string type;
//     std::string username;
//     double credit;
//     std::vector<Game> collection;
    
//     void sellGame(std::string name, double price);
//     void buyGame(std::string game, std::string seller);
//     void addCredits(double credit);
//     void listItems(std::string choice);
// }; 

// Member initialization
User::User(const std::string& username, const std::string& type, double credit)
    : Account(username, type, credit) {}
    
void User::sellGame(const std::string& name, double price) {
    // account that is buy standard cannot sell
    if (type == "BS") {
        return;
    }
    Account::sellGame(name, price);
}

void User::buyGame(const std::string& name, const std::string& seller) {
    // account that is sell standard cannot buy
    if (type == "SS") {
        return;
    }
    Account::buyGame(name, seller);
}

