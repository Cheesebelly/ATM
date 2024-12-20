#include "users.h"

users::users(const std::string& input) : input(input), db(nullptr), stmt(nullptr)
{
 int rc = sqlite3_open("../atm.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }
}

users::~users()
{
    sqlite3_close(db);
}

void users::run()
{
    const char *sql = "SELECT * FROM users";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::cout << "ID: " << sqlite3_column_int(stmt, 0) << std::endl;
        std::cout << "Name: " << sqlite3_column_text(stmt, 1) << std::endl;
        std::cout << "achternaam: " << sqlite3_column_text(stmt, 2) << std::endl;
        std::cout << "Pincode: " << sqlite3_column_int(stmt, 3) << std::endl;
    }
        login* l = new login();
        l->run();
    sqlite3_finalize(stmt);
}
