#include <string>

#include "../generateRandom/GenerateRandom.hpp"
#include "../user/User.hpp"
#include "./Transactions.hpp"

using namespace std;


Transaction::Transaction(User *sender, User *receiver, double sum) {
    this->sender        = sender;
    this->receiver      = receiver;
    this->sum           = sum;
    this->transactionID = getRandomString(32);
    this->signature     = sender->signTransaction(getValuesAsString());

    if (sender->getBalance() - sum < 0) {
        this->signature = "false";
    } else {
        this->sender->updateBalance(-sum);
    }
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
