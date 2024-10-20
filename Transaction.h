#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

class Transaction {
public:
    Transaction(const std::string& type, double amount);

    std::string getTransactionDetails() const;

private:
    std::string type;
    double amount;
    std::time_t time;
};

#endif
