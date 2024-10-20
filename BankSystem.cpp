#include "BankSystem.h"
#include <iostream>
#include <stdexcept>

void BankSystem::createAccount(const std::string& name, const std::string& accNumber) {
    BankAccount newAccount(name, accNumber);
    accounts[accNumber] = newAccount;
}

void BankSystem::deposit(const std::string& accNumber, double amount) {
    if (accounts.find(accNumber) != accounts.end()) {
        accounts[accNumber].deposit(amount);
    } else {
        throw std::runtime_error("Account not found");
    }
}

void BankSystem::withdraw(const std::string& accNumber, double amount) {
    if (accounts.find(accNumber) != accounts.end()) {
        accounts[accNumber].withdraw(amount);
    } else {
        throw std::runtime_error("Account not found");
    }
}

double BankSystem::getBalance(const std::string& accNumber) {
    if (accounts.find(accNumber) != accounts.end()) {
        return accounts[accNumber].getBalance();
    } else {
        throw std::runtime_error("Account not found");
    }
}

void BankSystem::showAccountDetails(const std::string& accNumber) {
    if (accounts.find(accNumber) != accounts.end()) {
        accounts[accNumber].displayDetails(); // Assuming you have a display method in BankAccount
    } else {
        throw std::runtime_error("Account not found");
    }
}

void BankSystem::closeAccount(const std::string& accNumber) {
    if (accounts.find(accNumber) != accounts.end()) {
        accounts.erase(accNumber);
    } else {
        throw std::runtime_error("Account not found");
    }
}

void BankSystem::updateAccount(const std::string& accNumber, const std::string& newName) {
    if (accounts.find(accNumber) != accounts.end()) {
        accounts[accNumber].setName(newName); // Assuming you have a setName method in BankAccount
    } else {
        throw std::runtime_error("Account not found");
    }
}
