#include <string>

#include "../merkleTree/MerkleTree.hpp"
#include "./Block.hpp"

using namespace std;


Block::Block() {
    this->timeStamp       = time(0);
    this->dificultyTarget = 4;
    this->version         = 1.00;
    this->nonce           = -1; // Genesis Block Anotation
    this->merkelRootHash  = merkelRootHash;
}

Block::Block(long int nonce, string merkleRootHash) {
    this->version         = 1.00;
    this->timeStamp       = time(0);
    this->dificultyTarget = 4;
    this->nonce           = nonce;
    this->merkelRootHash  = merkelRootHash;
}

string Block::blockToString() {
    string result = to_string(version);
    result += to_string(timeStamp);
    result += to_string(dificultyTarget);
    result += to_string(nonce);
    result += merkelRootHash;

    return result;
}
