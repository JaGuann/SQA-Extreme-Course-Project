#include <string>
#include <vector>
#include "game.h"
#include "account.h"
#include <iostream>

// Member intialization
Account::Account(const std::string& username, const std::string& type, double credit)
    : username(username), type(type), credit(credit) {}

// Getter functions 
const std::string& Account::getUsername() const {
    return username;
} 

const std::string& Account::getType() const {
    return type;
} 

double Account::getCredit() const {
    return credit;
}

const std::vector<Game>& Account::getCollection() const {
    return collection;
}

void Account::sellGame(const std::string& name, double price) {
    std::cout << "Game" << name << "is up for sale\n";
}

void Account::buyGame(const std::string& game, const std::string& seller) {
    std::cout << "Game" << game << "bought\n";
} 

void Account::addCredits(double amount) {
    if (amount > 0.0 && amount <= 1000.0) {
        credit += amount;
    }
}