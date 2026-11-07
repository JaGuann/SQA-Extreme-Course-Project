#include <string>
#include "game.h"


// Member initialization
Game::Game(const std::string& name, const std::string& seller, double price)
    : name(name), seller(seller), price(price) {}
    
// Getter functions 
const std::string& Game::getName() const {
    return name;
} 

const std::string& Game::getSeller() const {
    return seller;
} 

double Game::getPrice() const {
    return price;
}
