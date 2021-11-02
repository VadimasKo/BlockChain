#pragma once
#include <vector>

#include "Transactions.hpp"

using namespace std;

class TransactionPool {
    private:
        vector<Transaction> transactions;
    public:
        vector<Transaction> getPartOfTransactions(int size);
        size_t size();
        void addNewTransaction(Transaction transaction);
};