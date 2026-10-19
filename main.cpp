#include <iostream>

int main() { 
    std::string command;
    std::string in;
    double credit;

    // Display of commands that user can choose to use
    std::cout << "Welcome\n";
    std::cout << "Choose command\n";
    std::cout << "Login\n";
    std::cout << "Logout\n";
    std::cout << "create \n";
    std::cout << "delete\n";
    std::cout << "sell\n";
    std::cout << "buy\n";
    std::cout << "refund\n";
    std::cout << "add credit\n";
    std::cout << "command: ";
    std::cin >> command;
    if (command == "login"){
        std::cout << "log in?(y/n): ";
        std::cin >> in;
    }
    else if (command == "logout") {
        std::cout << "confirm logout?(y/n): ";
        std::cin >> in; 
        std::cout << "Successfully logged out";
    } 
    else if (command == "sell") {
        std::cout << "sell game?(y/n): ";
        std::cin >> in;
        std::cout << "game to sell?: ";
        std::cin >> in; 
        std::cout << "game " + in  + " is up for sale";
    } 

    else if (command == "buy") {
        std::cout << "buy game?(y/n): ";
        std::cin >> in;
        std::cout << "game to buy?: ";
        std::cin >> in;
        std::cout << "game " + in + " bought";
    } 

    else if (command == "refund") {
        std::cout << "refund?(y/n): ";
        std::cin >> in;
        std::cout << "game to refund?: ";
        std::cin >> in; 
        std::cout << "Game refunded";
    }

    else if (command == "credit") {
        std::cout << "Add credit?(y/n)?: ";
        std::cin >> in;
        std::cout << "How much credit to add?: ";
        std::cin >> credit;
        std::cout << "$" << credit << " has been added to account!"; 

    }

    else {
        std::cout << "Invalid command! Please choose a valid command listed above: ";
    }


    return 0;
}