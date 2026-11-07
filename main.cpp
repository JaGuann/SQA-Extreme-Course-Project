#include <iostream>
#include <string>
int main() { 
    std::string command;
    std::string in;
    double credit;

    // makes sure no command can be used until logged in
    bool isLogin = false;

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
    
     
    // validation loop if user chooses not to input one of the choices given

    while (true){
        std::cout << "command: ";
        if (!std::getline(std::cin, command)){
            break;
        }    
        
        if (command != "login" && 
            command != "logout" &&
            command != "create" &&
            command != "delete" &&
            command != "sell" &&
            command != "buy" &&
            command != "refund" &&
            command != "add credit") { 
            std::cout << "Invalid command! Please choose a valid command listed above: ";
            // If input user has given is one of the choices then input is valid and we break the loop and continue
            continue;
        }       

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

        else if (command == "add credit") {
            std::cout << "Add credit?(y/n)?: ";
            std::cin >> in;
            std::cout << "How much credit to add?: ";
            std::cin >> credit;
            std::cout << "$" << credit << " has been added to account!"; 

        }
    }
    return 0;
}