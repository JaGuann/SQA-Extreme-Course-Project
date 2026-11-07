#include <iostream>
#include <string>
#include <vector>
#include "account.h"
#include "user.h"
#include "admin_user.h"
#include "game.h"


int main() { 

    std::string command;
    std::string in;
    double credit = 0.0;

    // makes sure no command can be used until logged in
    bool isLogin = false;
    
    // Track the session once user logs out
    Account* currentUser = nullptr;
    // not nullptr if user type that is logged in is admin
    Admin_User* adminUser = nullptr;
    double creditAddSession = 0.0;

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
            // if end of file as been reached we break
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
            std::cout << "Invalid command! Please choose a valid command listed above:\n";
            // If input user has given is one of the choices then input is valid and we break the loop and continue
            continue;
        }       

        if (command == "login"){
            if (isLogin) {
                std::cout << "Unsuccessful Transaction: Already logged in!\n";
                continue;
            } 

            std::cout << "Username: ";
            std::string username;
            
            if (!std::getline(std::cin, username)){
                break;
            }

            std::cout << "User Type(admin, full-standard, buy-standard, sell-standard): ";
            std::string userType;
            if (!std::getline(std::cin, userType)){
                break;
            }

            if (userType == "admin" || "AA") {
                adminUser = new Admin_User(username, 1000.0);
                currentUser = adminUser;
            } 
            else if (userType == "buy-standard" || "BS") {
                currentUser = new User(username, "BS", 500.0);
            }
            else if (userType == "sell-standard" || "SS") {
                currentUser = new User(username, "SS", 500.0);
            }
            else {
                currentUser = new User(username, "FS", 500.0);
            }

            isLogin = true;
            creditAddSession = 0.0;
            std::cout << "Succesfully logged in as " << currentUser->getUsername() << " Type(" << currentUser->getType() << ")\n";
        }

        // if user is not logged in other commands will not work until user logs in
        else if (!isLogin) {
            std::cout << "Unsuccessful Transaction: must be logged in to use command\n";
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