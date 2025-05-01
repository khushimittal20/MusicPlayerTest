#include "User.h"

User::User(std::string uname, std::string pass)
    : username(uname), password(pass) {}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

bool User::validateLogin(const std::string& uname, const std::string& pass) const {
    return uname == username && pass == password;
}
