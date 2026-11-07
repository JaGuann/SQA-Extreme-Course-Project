#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
#include "game.h"



class Account {
protected:
    std::string type;
    std::string username;
    double credit;
    std::vector<Game> collection;
    

public:
    // Account constructor
    Account(const std::string& name, const std::string& type, double credit);

    void sellGame(const std::string& name, double price);
    void buyGame(const std::string& game, const std::string& seller);
    void addCredits(double credit);
    void listItems(const std::string& choice);

    // Account getters
    const std::string& getUsername() const;
    const std::string& getType() const;
    double getCredit() const;
    const std::vector<Game>& getCollection() const;

}; 

#endif