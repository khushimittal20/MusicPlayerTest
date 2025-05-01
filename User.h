#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;

public:
    User(std::string uname, std::string pass);
    std::string getUsername() const;
    std::string getPassword() const;
    bool validateLogin(const std::string& uname, const std::string& pass) const;
};

#endif 
