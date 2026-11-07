#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
private:
    std::string name;
    std::string seller;
    double price;

public:
// Game constructuer
    Game(const std::string& name, const std::string& seller, double price);
    
    // getters for the name of game, seller, and the price
    const std::string& getName() const;
    const std::string& getSeller() const;   
    double getPrice() const;

};

#endif