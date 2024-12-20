#include "sqlite/sqlite3.h"
#include "users.h"
#include "login.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    std::cout << "say profile:"<<  std::endl;
    std::string input;
    std::cin >> input;
    if (input == "profile"){
        users* u = new users(input);
        u->run();
    }
    if (input == "login"){
        login* l = new login();
        l->run();
    }
}