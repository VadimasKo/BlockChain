#include <string>
#include <iostream>

#include "./Block.hpp"

using namespace std;


Block::Block(string merkelRootHash, string prevBlockHash) {
    this->version         = 1.00;
    this->timeStamp       = time(0);
    this->nonce           = -1;
    this->dificultyTarget = 3;
    this->prevBlockHash   = prevBlockHash;
    this->merkelRootHash  = merkelRootHash;
    displayBlock();

}

Block::Block(long int nonce, string merkelRootHash, string prevBlockHash) {
    this->prevBlockHash   = prevBlockHash;
    this->version         = 1.00;
    this->timeStamp       = time(0);
    this->nonce           = nonce;
    this->dificultyTarget = 3;
    this->merkelRootHash  = merkelRootHash;
    displayBlock();

}

string Block::blockToString() {
    string result = to_string(version);
    result += prevBlockHash;
    result += to_string(timeStamp);
    result += to_string(nonce);
    result += to_string(dificultyTarget);
    result += merkelRootHash;
    
    return result;
}

int Block::getDificulty() {
    return dificultyTarget;
}

void Block::displayBlock() {
    cout<<"======== New Block"<<endl;
    cout<<"prevBlock \t"<<prevBlockHash<<endl;
    cout<<"timeStamp \t"<<to_string(timeStamp)<<endl;
    cout<<"nonce     \t"<<to_string(nonce)<<endl;
    cout<<"difTarget \t"<<to_string(dificultyTarget)<<endl;
    cout<<"merkelRoot\t"<<merkelRootHash<<endl<<endl;
}