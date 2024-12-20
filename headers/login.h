#include <sqlite3.h>
#include <iostream>
class login
{
private:
    sqlite3 *db;
    sqlite3_stmt *stmt;
    std::string input;
public:
    login(/* args */);
    ~login();
    void run();
};
