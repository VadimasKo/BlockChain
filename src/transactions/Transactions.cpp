#include <string>
#include <iostream>

#include "../generateRandom/GenerateRandom.hpp"
#include "../user/User.hpp"
#include "./Transactions.hpp"

using namespace std;


Transaction::Transaction(User *sender, User *receiver, double sum) {
    this->receiver      = receiver;
    this->sender        = sender;
    this->sum           = sum;
    this->transactionID = getRandomString(32);
    this->signature =  ((sender->getBalance() - sum) < 0) ?
      sender->signTransaction(getValuesAsString()) : "false";
    
    // cout<<"transID  \t"<<this->transactionID<<endl;
    // cout<<"receiver \t"<<this->receiver<<endl;
    // cout<<"sender   \t"<<this->sender<<endl;
    // cout<<"sum      \t"<<this->sum<<endl;
    // cout<<"signature\t"<<this->signature<<endl<<endl;
}

Transaction::Transaction(const Transaction &other) {
    receiver      = other.receiver;
    sender        = other.sender;
    signature     = other.signature;
    sum           = other.sum;
    transactionID = other.transactionID;
}
        
Transaction& Transaction::operator = (const Transaction &other) {
    receiver      = other.receiver;
    sender        = other.sender;
    signature     = other.signature;
    sum           = other.sum;
    transactionID = other.transactionID;
    return *this;
}


string Transaction::getValuesAsString() {
    return sender->getPublicKey() + receiver->getPublicKey() + transactionID + to_string(sum);
}

string Transaction::getTransactionString() {
    return getValuesAsString() + signature;
}

bool Transaction::verifyTransaction() {
    return sender->verifyTransaction(getValuesAsString(), signature);
}

void Transaction::completeTransaction() {
    sender->updateBalance(-1*sum);
    receiver->updateBalance(sum);
}

void generateRandomTransactions( vector<Transaction> &transactionPool,  vector<User> &users) {
  for(int i = 0; i<100; i++) {
    Transaction newTransaction(
      &users[getRandomUser()],
      &users[getRandomUser()],
      getRandomSum()*1.0
    );
    transactionPool.push_back(newTransaction);
  }
}