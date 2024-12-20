#include "login.h"

std::unordered_map<std::string, std::pair<std::string, std::string>> userDatabase;

login::login(/* args */)
{
    if (sqlite3_open("../atm.db", &db) != SQLITE_OK)
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
bool login::verifyPincode(const std::string& username, const std::string& pincode, const std::string& id){
    auto it = userDatabase.find(username);
    if (it != userDatabase.end()){
        return it->second.second == pincode;
    }
    return false;
}

void login::loadUsersFromDatabase()
{
    const char* sql = "SELECT id, gebruiker, pincode FROM users";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to fetch data: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const unsigned char* idText = sqlite3_column_text(stmt, 0);
        const unsigned char* usernameText = sqlite3_column_text(stmt, 1);
        const unsigned char* pincodeText = sqlite3_column_text(stmt, 2);
  
        if (usernameText && pincodeText && idText) {
            std::string id = reinterpret_cast<const char*>(idText);
            std::string username = reinterpret_cast<const char*>(usernameText);
            std::string pincode = reinterpret_cast<const char*>(pincodeText);
            userDatabase[username] = std::make_pair(id, pincode);
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
        std::string id = userDatabase[username].first;
        if(verifyPincode(username, pincode, userDatabase[username].first)){
            std::cout << "Login successful!" << std::endl;
            std::cout << "ID: " << id << std::endl;
            home* l = new home(username, pincode, id);
            l->run();
        } else {
            std::cout << "Invalid pincode!" << std::endl;
        }
    } else {
        std::cout << "User does not exist!" << std::endl;
    }
}