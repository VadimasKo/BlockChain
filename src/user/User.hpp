#pragma once
#include <string>

using namespace std;

class User {
    private:
        double balance;
        string secretKey;
        string publicKey;
    public:
        User(double initialBalance);
        double getBalance();
        string signTransaction(string transaction);
        bool verifyTransaction(string transaction, string transactionHash);
};
