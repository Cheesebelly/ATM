#include "users.h"

users::users() : db(nullptr), stmt(nullptr)
{
    sqlite3_open("database.db", &db);
    const char *sql = "SELECT * FROM users";
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::cout << "ID: " << sqlite3_column_text(stmt, 0) << std::endl;
        std::cout << "Name: " << sqlite3_column_text(stmt, 1) << std::endl;
        sqlite3_close(db);
    }
}

users::~users()
{
    sqlite3_close(db);
}

void users::run()
{
    std::cout << "Hello, world!" << std::endl;
}
