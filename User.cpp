#include "User.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


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

bool User::registerUser(const std::string& username, const std::string& password) {
    if (userExists(username)) {
        std::cout << "Username already exists.\n";
        return false;
    }

    std::ofstream file("users.txt", std::ios::app);  
    if (file.is_open()) {
        file << username << " " << password << "\n";  
        file.close();
        std::cout << "Registration successful!\n";
        return true;
    }

    std::cout << "Error opening file for registration.\n";
    return false;
}

// Check if the username exists
bool User::userExists(const std::string& username) {
    std::ifstream file("users.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string storedUsername, storedPassword;
        ss >> storedUsername >> storedPassword;

        if (storedUsername == username) {
            return true;  
        }
    }
    return false;
}


bool User::validateLoginFromFile(const std::string& username, const std::string& password) {
    std::ifstream file("users.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string storedUsername, storedPassword;
        ss >> storedUsername >> storedPassword;

        if (storedUsername == username && storedPassword == password) {
            return true;  
        }
    }
    return false;
}