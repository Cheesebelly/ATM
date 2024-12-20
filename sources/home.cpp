#include "home.h"
home::home(const std::string& username, const std::string& princode, const std::string& id) : username(username), pincode(pincode), id(id)
{
}

home::~home()
{
}

void home::run()
{
    std::cout << "Welcome to the ATM: " << username << "!" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Tipe 1 to withdraw money" << std::endl;
    std::cout << "Tipe 2 to deposit money" << std::endl;
    std::cout << "Tipe 3 to check balance" << std::endl;
    std::cout << "Tipe 4 to make a new card" << std::endl;
    std::cout << "Tipe 5 to exit" << std::endl;
}