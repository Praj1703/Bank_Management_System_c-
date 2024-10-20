#include "Transaction.h"
#include <sstream>
#include <iomanip>

Transaction::Transaction(const std::string& type, double amount)
    : type(type), amount(amount), time(std::time(nullptr)) {}

std::string Transaction::getTransactionDetails() const {
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&time));
    
    std::ostringstream oss;
    oss << "Transaction Type: " << type << "\n"
        << "Amount: " << amount << "\n"
        << "Time: " << buffer;
    return oss.str();
}
