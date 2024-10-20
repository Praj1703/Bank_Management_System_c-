#include "BankAccount.h"
#include <iostream>
#include <stdexcept>

BankAccount::BankAccount() : name(""), accNumber(""), balance(0.0) {} // Initialize with default values

BankAccount::BankAccount(const std::string& name, const std::string& accNumber)
    : name(name), accNumber(accNumber), balance(0.0) {}

void BankAccount::deposit(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Deposit amount must be positive");
    }
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive");
    }
    if (balance < amount) {
        throw std::runtime_error("Insufficient funds");
    }
    balance -= amount;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::displayDetails() const {
    std::cout << "Account Holder: " << name << "\n"
              << "Account Number: " << accNumber << "\n"
              << "Current Balance: $" << balance << "\n";
}

void BankAccount::setName(const std::string& newName) {
    name = newName;
}
