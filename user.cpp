#include <string>
#include <vector>
#include "account.h"
#include "game.h"

class user : public Account {
protected:
    std::string type;
    std::string username;
    double credit;
    std::vector<Game> collection;
    
    void sellGame(std::string name, double price);
    void buyGame(std::string game, std::string seller);
    void addCredits(double credit);
    void listItems(std::string choice);
};