#include <string>

#include "./Block.hpp"

using namespace std;


Block::Block(string merkelRootHash) {
    this->version         = 1.00;
    this->timeStamp       = time(0);
    this->nonce           = -1;
    this->dificultyTarget = 4;
    this->merkelRootHash  = merkelRootHash;
}

Block::Block(long int nonce, string merkelRootHash) {
    this->version         = 1.00;
    this->timeStamp       = time(0);
    this->nonce           = nonce;
    this->dificultyTarget = 4;
    this->merkelRootHash  = merkelRootHash;
}

string Block::blockToString() {
    string result = to_string(version);
    result += to_string(timeStamp);
    result += to_string(nonce);
    result += to_string(dificultyTarget);
    result += merkelRootHash;

    return result;
}