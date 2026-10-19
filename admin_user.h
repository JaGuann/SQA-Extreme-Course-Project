#include <string>
#include <vector>
#include "account.h"
#include "game.h"

class Admin_User : public Account {
protected:
    std::string type;
    std::string username;
    double credit;
    std::vector<Game> collection;
    
    void createUser(std::string name, std::string type);
    void deleteUser(std::string name);
    void refund(std::string buyer, std::string seller, double credit);
    void sellGame(std::string name, double price);
    void buyGame(std::string game, std::string seller);
    void addCredits(double credit, std::string name);
    void listItems(std::string choice);
    void printAccounts();
};