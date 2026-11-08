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

            if (userType == "admin" || userType == "AA") {
                adminUser = new Admin_User(username, 1000.0);
                currentUser = adminUser;
            } 
            else if (userType == "buy-standard" || userType == "BS") {
                currentUser = new User(username, "BS", 500.0);
            }
            else if (userType == "sell-standard" || userType == "SS") {
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

        // Logout functionality
        else if (command == "logout") {
            std::cout << "Succesfully Logged out!\n";
            // everything is cleared
            delete currentUser;
            currentUser = nullptr;
            adminUser = nullptr;
            isLogin = false;
            creditAddSession = 0.0;
        } 

        // Only admin can create accounts
        else if (command == "create"){
            if (adminUser == nullptr){
                std::cout << "Unsuccessful Transaction! Must be Admin user type to create\n";
                continue;
            }

            std::string newUsername, newType;
            std::cout << "Enter username: ";
            std::getline(std::cin, newUsername);

            // user cannot exceed 15 characters
            if (newUsername.length() > 15){
                std::cout << "Unsuccessful Transaction! username cannot exceed 15 characters\n";
            }

            std::cout << "Enter User type(admin, full-standard, buy-standard, sell-standard): ";
            std::getline(std::cin, newType);

            // We call admin_user createuser method 
            adminUser->createUser(newUsername, newType);

        }

        // Delete is only for admin type users
        else if (command == "delete") {
            // if adminuser points to nothing premission is denied
            if (adminUser == nullptr){
                std::cout << "Unsuccessful Transaction! Must be Admin user type to delete\n";
                continue;
            }

            std::string targetUser;
            std::cout << "Enter username to delete: ";
            std::getline(std::cin, targetUser);

            // if the targeruser points to the current user, doesnt delete because cannot delete current user
            if (targetUser == currentUser->getUsername()){
                std::cout << "Unsuccessful Transaction! Cannot delete current user\n";
                continue;
            } 

            // Call admin_user deleteUser method
            adminUser->deleteUser(targetUser);
        }

        // Sell game
        else if (command == "sell") {
            // points to see if the usertype is buy standard
            if (currentUser->getType() == "BS"){
                std::cout << "Unsuccessfull Transaction: buy-standard users cannot sell games!\n";
                continue;
            }

            std::string gameName;
            double price;

            std::cout << "Game to sell?: ";
            std::getline(std::cin, gameName);
            // checks if game length is more than 25 characters
            if (gameName.length() > 25) {
                std::cout << "Unsuccessful Transaction! Game name cannot exceed 25 characters!\n";
                continue;
            }

            std::cout << "Price?: ";
            // if user tries to input anything other than a double the input it uses clear to to flag the error
            // then it uses ignore to throw it out of memory
            if (!(std::cin >> price)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Unsuccessful Transaction! price format is not valid!\n";
                continue;
            }

            // clears newline from stream
            std::cin.ignore(1000, '\n');

            if (price <= 0.0 || price > 999.99) {
                std::cout << "Unsuccessful Transaction! Price must be between $0.01 and $999.99!\n";
            }

            // Call account or user sellGame method
            currentUser->sellGame(gameName, price);
        } 

        // Buy games
        else if (command == "buy") {
             if (currentUser->getType() == "SS"){
                std::cout << "Unsuccessfull Transaction: sell-standard users cannot buy games!\n";
                continue;

            } 

            std::string gameName, sellerName;
            std::cout << "Game to buy?: ";
            std::getline(std::cin, gameName);
            std::cout << "Sellers name: ";
            std::getline(std::cin, sellerName);

            // Calls account or user buygame method
            currentUser->buyGame(gameName, sellerName);
        } 

        // Refund Only admin can do
        else if (command == "refund") {
            if (adminUser == nullptr){
                std::cout << "Unsuccessful Transaction! Must be Admin user type to refund\n";
                continue;
            }

            std::string buyer, seller;
            double refundAmount;

            std::cout << "Buyer username: ";
            std::getline(std::cin, buyer);
            std::cout << "Seller username: ";
            std::getline(std::cin, seller);

            std::cout << "Refund amount: ";

            //similar to sell game if refundamount is not a double it uses clear to to flag the error
            // then it uses ignore to throw it out of memory
            if (!(std::cin >> refundAmount)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Unsuccessful Transaction! price format is not valid!\n";
                continue;
            }

            std::cin.ignore(1000, '\n');

            // call admin_user refund
            adminUser->refund(buyer, seller, refundAmount);
        }

        //
        else if (command == "add credit") {
           std::string targetUser = currentUser->getUsername();

           // Check if user is currently admin type
           if (adminUser != nullptr){
                std::cout << "Enter username of account to add to: ";
                std::getline(std::cin, targetUser);
           }

           std::cout << "How much credit to add?: ";
           //similar to sell game and refund if input is not a double it uses clear to to flag the error
            // then it uses ignore to throw it out of memory
           if (!(std::cin >> credit)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Unsuccessful Transaction! price format is not valid!\n";
                continue;
            }
            std::cin.ignore(1000, '\n'); 

            // negative credit cannot exist
            if (credit <= 0.0) {
                std::cout << "Unsuccessful Transaction! Credit amount must be positive.\n";
                continue;
            }

            // max credit session cannot exceed
            if (creditAddSession + credit > 1000.00) {
                std::cout << "Unsuccessful Transaction! Max credit for session is $1000.00";
            }

            // add credit to current credit session that has been added
            creditAddSession += credit; 

            if (adminUser != nullptr) {
                // We call admin_user::addcredits
                adminUser->addCredits(credit, targetUser);
            }
            else {
                // call account::addcredits
                currentUser->addCredits(credit);
                std::cout << "$" << credit << " has been added to account\n";
            }

        }
    }

    // remove dynamic memory
    if (currentUser != nullptr) {
        delete currentUser;
    }

    return 0;
}