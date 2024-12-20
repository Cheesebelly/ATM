#ifndef HOME_H_
#define HOME_H_

#include <iostream>
#include <string>
#include "login.h"

class home
{
private:
     std::string username;
     std::string pincode;
     std::string id;
 public:
    home(const std::string& username, const std::string& pincode, const std::string& id);
    ~home();
    void run();
};
#endif