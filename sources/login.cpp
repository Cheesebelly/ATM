#include "login.h"

std::unordered_map<std::string, std::string> userDatabase;

login::login(/* args */)
{
    if (sqlite3_open("E:\\CPP\\ATM\\atm.db", &db) != SQLITE_OK)
    {
        std::cerr << "Error opening database!" << std::endl;
    } else {
        loadUsersFromDatabase();
    }
}

login::~login()
{
    sqlite3_close(db);
}

bool login::userExists(const std::string& username){
    return userDatabase.find(username) != userDatabase.end();
}
bool login::verifyPincode(const std::string& username, const std::string& pincode){
    auto it = userDatabase.find(username);
    if (it != userDatabase.end()){
        return it->second == pincode;
    }
    return false;
}

void login::loadUsersFromDatabase()
{
    const char* sql = "SELECT gebruiker, pincode FROM users";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to fetch data: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const unsigned char* usernameText = sqlite3_column_text(stmt, 0);
        const unsigned char* pincodeText = sqlite3_column_text(stmt, 1);

        if (usernameText && pincodeText) {
            std::string username = reinterpret_cast<const char*>(usernameText);
            std::string pincode = reinterpret_cast<const char*>(pincodeText);
            userDatabase[username] = pincode;
        } else {
            std::cerr << "Null value encountered in database row." << std::endl;
        }
    }

    sqlite3_finalize(stmt);
}

void login::run()
{
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;

    if (userExists(username))
    {
        std::string pincode;
        std::cout << "Enter pincode: ";
        std::cin >> pincode;
        if(verifyPincode(username, pincode)){
            std::cout << "Login successful!" << std::endl;
        } else {
            std::cout << "Invalid pincode!" << std::endl;
        }
    } else {
        std::cout << "User does not exist!" << std::endl;
    }
}