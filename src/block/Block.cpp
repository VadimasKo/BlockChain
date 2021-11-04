#include <string>
#include <iostream>

#include "../generateHash/GenerateHash.hpp"
#include "../merkelTree/MerkelTree.hpp"
#include "../transactions/Transactions.hpp"
#include "./Block.hpp"

using namespace std;


Block::Block(string merkelRootHash, string prevBlockHash) {
    this->version         = 1.00;
    this->timeStamp       = time(0);
    this->nonce           = -1;
    this->dificultyTarget = 4;
    this->prevBlockHash   = prevBlockHash;
    this->merkelRootHash  = merkelRootHash;
    displayBlock();

}

Block::Block(long int nonce, string merkelRootHash, string prevBlockHash) {
    this->prevBlockHash   = prevBlockHash;
    this->version         = 1.00;
    this->timeStamp       = time(0);
    this->nonce           = nonce;
    this->dificultyTarget = 4;
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
    cout<<"==========\tNew Block"<<endl;
    cout<<"prevBlock \t"<<prevBlockHash<<endl;
    cout<<"timeStamp \t"<<to_string(timeStamp)<<endl;
    cout<<"nonce     \t"<<to_string(nonce)<<endl;
    cout<<"difTarget \t"<<to_string(dificultyTarget)<<endl;
    cout<<"merkelRoot\t"<<merkelRootHash<<endl<<endl;
}

Block generateGenesisBlock(vector<User> &users) {
  User genesisUser(100.0*1000);
  vector<Transaction> genesisTransactions;
  MerkelTree transactionTree;
  
  for(int i = 0; i < 1000; i++) {
    users.push_back(User(0.0));
    User* receiver = &users[i];
    genesisTransactions.push_back(Transaction(&genesisUser, receiver, 100.0));
  }
  cout<<"==========\t1000 Random Users Created\n\n";
  for(auto transaction : genesisTransactions) {
    transactionTree.push_back(getHash(transaction.getTransactionString()));
  }
  return Block(transactionTree.getRootHash(), "");
}

long int mineWorkProof(Block &previousBlock) {
  int dificulty    = previousBlock.getDificulty();
  string lastBlock = previousBlock.blockToString();
  string target    = string(dificulty,'0');
  
  for(long int i = 0; true; i++) {
    string hash = getHash(lastBlock + to_string(i));
    if(hash.substr(0,dificulty) == target) return i;
  }
}
