#include "sqlite/sqlite3.h"
#include <iostream>
using namespace std;

void printUsers(sqlite3* db) {
    const char* selectSQL = "SELECT id, gebruiker, achternaam, pincode FROM users";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
        return;
    }

    cout << "ID | Name | Surname | Pincode" << endl;
    cout << "-----------------------------" << endl;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char* name = sqlite3_column_text(stmt, 1);
        const unsigned char* surname = sqlite3_column_text(stmt, 2);
        int pincode = sqlite3_column_int(stmt, 3);

        cout << id << " | " << name << " | " << surname << " | " << pincode << endl;
    }

    if (rc != SQLITE_DONE) {
        cerr << "Failed to execute statement: " << sqlite3_errmsg(db) << endl;
    }

    sqlite3_finalize(stmt);
}

int main() {
    sqlite3 *db;
    const char* dbPath = "C:/Users/chris/OneDrive/Bureaublad/CPP/ATM/atm.db";
    int rc = sqlite3_open(dbPath, &db);

    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return rc;
    } else {
        cout << "Opened database successfully" << endl;
    }

    const char* createUsersTableSQL = 
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY, "
        "name TEXT, "
        "surname TEXT, "
        "pincode INT)";
    
    rc = sqlite3_exec(db, createUsersTableSQL, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
    } else {
        cout << "Users table created successfully" << endl;
    }

    // Print the data from the users table
    printUsers(db);

    // Close the database connection
    sqlite3_close(db);
    cout << "Closed database successfully" << endl;
    return 0;
}