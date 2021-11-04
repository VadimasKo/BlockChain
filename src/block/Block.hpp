#pragma once
#include <string>
#include <ctime>

using namespace std;

class Block {
    private:
        int  dificultyTarget;
        double version = 1.00;
        long int nonce; //solution to prev Block (proof of work)
        string merkelRootHash;
        string prevBlockHash;
        time_t timeStamp;

    public:
        Block() {};
        Block(string merkelRootHash, string prevBlockHash); //Genesis Block
        Block(long int nonce, string merkelRootHash, string prevBlockHash);
        string blockToString();
        int getDificulty();
        void displayBlock();
};
