#include <iostream>
#include <string>
#include "BankSystem.h"

int main() {
    BankSystem bankSystem;
    int choice;

    do {
        std::cout << "\n--- Bank System Menu ---\n";
        std::cout << "1. Create Bank Account\n";
        std::cout << "2. Deposit Amount\n";
        std::cout << "3. Withdraw Amount\n";
        std::cout << "4. Balance Enquiry\n";
        std::cout << "5. Show Account Holder's Full Details\n";
        std::cout << "6. Close Bank Account\n";
        std::cout << "7. Update Bank Account\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, accNumber;
                std::cout << "Enter Account Holder Name: ";
                std::cin.ignore(); // Clear newline from buffer
                std::getline(std::cin, name);
                std::cout << "Enter Account Number: ";
                std::getline(std::cin, accNumber);
                bankSystem.createAccount(name, accNumber);
                std::cout << "Account created successfully!\n";
                break;
            }
            case 2: {
                std::string accNumber;
                double amount;
                std::cout << "Enter Account Number: ";
                std::cin.ignore();
                std::getline(std::cin, accNumber);
                std::cout << "Enter Deposit Amount: ";
                std::cin >> amount;
                bankSystem.deposit(accNumber, amount);
                std::cout << "Deposit successful!\n";
                break;
            }
            case 3: {
                std::string accNumber;
                double amount;
                std::cout << "Enter Account Number: ";
                std::cin.ignore();
                std::getline(std::cin, accNumber);
                std::cout << "Enter Withdraw Amount: ";
                std::cin >> amount;
                try {
                    bankSystem.withdraw(accNumber, amount);
                    std::cout << "Withdrawal successful!\n";
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 4: {
                std::string accNumber;
                std::cout << "Enter Account Number: ";
                std::cin.ignore();
                std::getline(std::cin, accNumber);
                double balance = bankSystem.getBalance(accNumber);
                std::cout << "Current Balance: " << balance << "\n";
                break;
            }
            case 5: {
                std::string accNumber;
                std::cout << "Enter Account Number: ";
                std::cin.ignore();
                std::getline(std::cin, accNumber);
                bankSystem.showAccountDetails(accNumber);
                break;
            }
            case 6: {
                std::string accNumber;
                std::cout << "Enter Account Number: ";
                std::cin.ignore();
                std::getline(std::cin, accNumber);
                bankSystem.closeAccount(accNumber);
                std::cout << "Account closed successfully!\n";
                break;
            }
            case 7: {
                std::string accNumber;
                std::cout << "Enter Account Number: ";
                std::cin.ignore();
                std::getline(std::cin, accNumber);
                std::string newName;
                std::cout << "Enter New Account Holder Name: ";
                std::getline(std::cin, newName);
                bankSystem.updateAccount(accNumber, newName);
                std::cout << "Account updated successfully!\n";
                break;
            }
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
