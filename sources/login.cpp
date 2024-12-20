#include "login.h"

std::unordered_set<std::string> userDatabase = {"user1", "user2", "user3"};

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

void login::loadUsersFromDatabase()
{
const  char* sql = "SELECT gebruiker, pincode FROM users";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Error preparing statement!" << std::endl;
        return;
    }
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const char* username = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        const char* pincode = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        userDatabase.insert(username);
    }

    sqlite3_finalize(stmt);
}

void login::run()
{
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;

    login loginInstance;
    if (loginInstance.userExists(username))
    {
        std::cout << "User exists!" << std::endl;
    } else {
        std::cout << "User does not exist!" << std::endl;
    }
}