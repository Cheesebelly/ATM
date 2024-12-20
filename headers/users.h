#include <sqlite3.h>
#include <iostream>
#include "login.h"
class users
{
private:
    sqlite3 *db;
    sqlite3_stmt *stmt;
    std::string input;
public:
    users(const std::string& input);
    ~users();
    void run();
};