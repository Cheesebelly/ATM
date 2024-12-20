#include <sqlite3.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "home.h"

#ifndef LOGIN_H
#define LOGIN_H

class login
{
private:
    sqlite3 *db;
    sqlite3_stmt *stmt;
    std::string input;
    void loadUsersFromDatabase();
public:
    login(/* args */);
    ~login();
    void run();
    bool userExists(const std::string& username);
    bool verifyPincode(const std::string& username, const std::string& pincode, const std::string& id);
};

#endif
