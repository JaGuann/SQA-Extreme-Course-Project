#include <string>
#include <vector>
#include "account.h"
#include "game.h"

#ifndef ADMIN_USER_H
#define ADMIN_USER_H

class Admin_User : public Account {
public:
    // std::string type;
    // std::string username;
    // double credit;
    // std::vector<Game> collection;
    
    // Admin user constructor 
    Admin_User(const std::string& username, double credit = 0.0);
    
    void createUser(const std::string& name, const std::string& type);
    void deleteUser(const std::string& name);
    void refund(const std::string& buyer, const std::string& seller, double credit);
    // void sellGame(std::string name, double price);
    // void buyGame(std::string game, std::string seller);
    void addCredits(double credit, const std::string& name);
    void listItems(const std::string& choice);
    void printAccounts();
};

#endif