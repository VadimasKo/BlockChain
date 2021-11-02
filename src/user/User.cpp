#include <string>

#include "./User.hpp"
#include "../generateRandom/GenerateRandom.hpp"
#include "../generateHash/GenerateHash.hpp"

using namespace std;


User::User(double initialBalanace) {
    balance   = initialBalanace;
    secretKey = getRandomString(64);
    publicKey = getRandomString(64);
}

double User::getBalance() {
    return balance;
}

string User::signTransaction(string transaction) {
    return  getHash(getHash(transaction + secretKey) + publicKey);
}

bool User::verifyTransaction(string transaction, string transactionHash) {
    return signTransaction(transaction) == transactionHash;
}

