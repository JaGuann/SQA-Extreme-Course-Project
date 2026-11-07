#include <string>
#include <vector>
#include "account.h"
#include "game.h"
#include "admin_user.h"
#include <iostream>

// Member intialization
Admin_User::Admin_User(const std::string& username, double credit)
    : Account(username, "AA", credit) {}

void Admin_User::createUser(const std::string& name, const std::string& type){
    std::cout << "Status: Transaction successful " << name << "(" <<  type << ") account created\n";
} 

void Admin_User::deleteUser(const std::string& name) {
    std::cout << "Status: Transaction successful, account deleted\n";
} 

void Admin_User::refund(const std::string& buyer, const std::string& seller, double credit){
    std::cout << "Status: Transaction successful, game refunded\n";
}

void Admin_User::addCredits(double credit, const std::string& name) {
    std::cout << "$" << credit << " has been added to " << "account!\n";
}

