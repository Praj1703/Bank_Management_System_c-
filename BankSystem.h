#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <string>
#include <unordered_map>
#include "BankAccount.h"

class BankSystem {
private:
    std::unordered_map<std::string, BankAccount> accounts;

public:
    void createAccount(const std::string& name, const std::string& accNumber);
    void deposit(const std::string& accNumber, double amount);
    void withdraw(const std::string& accNumber, double amount);
    double getBalance(const std::string& accNumber);
    void showAccountDetails(const std::string& accNumber);
    void closeAccount(const std::string& accNumber);
    void updateAccount(const std::string& accNumber, const std::string& newName);
};

#endif
