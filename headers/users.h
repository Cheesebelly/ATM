#include <sqlite3.h>
#include <iostream>
class users
{
private:
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc = sqlite3_open("atm.db", &db);

public:
    users();
    ~users();
    void run();
};
