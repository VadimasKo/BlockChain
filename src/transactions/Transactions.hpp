#pragma once
#include "../user/User.hpp"

using namespace std;

class Transaction {
    private:
        User   *sender;
        User   *receiver;
        string signature;
        string transactionID;
        double sum;
    public:
        Transaction(User *sender, User *receiver, double sum);
        Transaction(const Transaction &other);              //copy constructor
        Transaction& operator = (const Transaction &other); //assignment operator
        string getValuesAsString();
        string getTransactionString();
        bool verifyTransaction();
};
