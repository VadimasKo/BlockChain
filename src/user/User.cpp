#include <string>
#include <iostream>

#include "./User.hpp"
#include "../generateRandom/GenerateRandom.hpp"
#include "../generateHash/GenerateHash.hpp"

using namespace std;


User::User(double initialBalanace) {
    balance   = initialBalanace;
    secretKey = getRandomString(32);
    publicKey = getRandomString(32);
    cout<<publicKey+'\t' + secretKey<<endl;
}

User::User(const User &other) {
    balance   = other.balance;
    secretKey = other.secretKey;
    publicKey = other.publicKey;
}

User& User::operator = (const User &other) {
    balance   = other.balance;
    secretKey = other.secretKey;
    publicKey = other.publicKey;
    return *this;
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
