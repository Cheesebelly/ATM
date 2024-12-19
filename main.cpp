#include "sqlite/sqlite3.h"
#include "users.h"
#include <iostream>
using namespace std;

int main() {
    users* u = new users();
    u->run();
}