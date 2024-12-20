#include "sqlite/sqlite3.h"
#include "users.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    std::cout << "say start:"<<  std::endl;
    std::string input;
    std::cin >> input;
    if (input == "start"){
        users* u = new users(input);
        u->run();
    }

}