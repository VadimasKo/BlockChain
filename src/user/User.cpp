#include <string>

#include "./User.hpp"
#include "../generateRandom/GenerateRandom.hpp"
#include "../generateHash/GenerateHash.hpp"

using namespace std;


User::User(double initialBalanace) {
    balance   = initialBalanace;
    secretKey = getRandomString(32);
    publicKey = getRandomString(32);
}


double User::getBalance() {
    return balance;
}

string User::getPublicKey() {
    return publicKey;
}

string User::signTransaction(string transaction) {
    return  getHash(transaction + secretKey);
}

bool User::verifyTransaction(string transaction, string transactionHash) {
    return signTransaction(transaction) == transactionHash;
}

void User::updateBalance(double delta) {
    balance += delta;
}
