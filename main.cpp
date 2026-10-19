#include <iostream>

int main() { 
    std::string command;
    std::string in;

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
    std::cin >> command;
    if (command == "login"){
        std::cout << "log in?(y/n)";
        std::cin >> in;
    }


    return 0;
}