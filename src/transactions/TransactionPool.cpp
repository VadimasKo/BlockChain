#include <vector>

#include "./TransactionPool.hpp"
#include "./Transactions.hpp"

using namespace std;


void TransactionPool::addNewTransaction(Transaction transaction) {
    transactions.push_back(transaction);
}

size_t TransactionPool::size() {
    return transactions.size();
}

vector<Transaction> TransactionPool::getPartOfTransactions(int size) {
    if (transactions.size() < size) {
        vector<Transaction> partOfTransactions(transactions.begin(), transactions.end());
        transactions.erase(transactions.begin(), transactions.end());
        return partOfTransactions;
    } else {
        vector<Transaction> partOfTransactions(transactions.begin(), transactions.end());
        transactions.erase(transactions.begin(), transactions.begin()+size);
        return partOfTransactions;
    }
}   
