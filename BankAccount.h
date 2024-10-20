#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string name;
    std::string accNumber;
    double balance;

public:
    BankAccount(); // Default constructor
    BankAccount(const std::string& name, const std::string& accNumber);
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
    void displayDetails() const;
    void setName(const std::string& newName);
};

#endif
