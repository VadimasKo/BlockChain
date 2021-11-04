#include <string>
#include <iostream>

#include "../generateRandom/GenerateRandom.hpp"
#include "../user/User.hpp"
#include "./Transactions.hpp"

using namespace std;


Transaction::Transaction(User *sender, User *receiver, double sum) {
    this->sender        = sender;
    this->receiver      = receiver;
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
    sender        = other.sender;
    receiver      = other.receiver;
    signature     = other.signature;
    transactionID = other.transactionID;
    sum           = other.sum;
}
        
Transaction& Transaction::operator = (const Transaction &other) {
    sender        = other.sender;
    receiver      = other.receiver;
    signature     = other.signature;
    transactionID = other.transactionID;
    sum           = other.sum;
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