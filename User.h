#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
private:
    std::string username;
    std::string password;
    std::vector<std::string> listeningHistory;

public:
    User(std::string uname, std::string pass);
    std::string getUsername() const;
    std::string getPassword() const;
    bool validateLogin(const std::string& uname, const std::string& pass) const;
    static bool registerUser(const std::string& username, const std::string& password);  
    static bool userExists(const std::string& username);  
    static bool validateLoginFromFile(const std::string& username, const std::string& password);  
    void addToHistory(const std::string& title);
    void showHistory() const;
};

#endif 
