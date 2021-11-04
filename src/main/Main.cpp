#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../block/Block.hpp"
#include "../generateHash/GenerateHash.hpp"
#include "../generateRandom/GenerateRandom.hpp"
#include "../merkelTree/MerkelTree.hpp"
#include "../transactions/Transactions.hpp"
#include "../user/User.hpp"

using namespace std;

string getRootHash(vector<Transaction> &transactionPool);
void completePendingTransactions(vector<Transaction> &transactionPool);


int main() {
  unordered_map<string, Block> blockChain;
  string lastBlockHash =  "Genesis";
  vector<User> users;
  users.reserve(1000);

  blockChain.insert({lastBlockHash, generateGenesisBlock(users)});
  
  while(true) { 
      vector<Transaction> transactionPool;
      transactionPool.reserve(150);

      generateRandomTransactions(transactionPool, users);

      long int proof = mineWorkProof(blockChain[lastBlockHash]);

      string rootHash = getRootHash(transactionPool);
      Block newBlock(proof, rootHash, lastBlockHash);
      lastBlockHash = getHash(newBlock.blockToString());
      blockChain.insert({ lastBlockHash, newBlock });
      completePendingTransactions(transactionPool);
      transactionPool.clear();
  }
}

string getRootHash(vector<Transaction> &transactionPool) {
  MerkelTree transactionTree;
  vector<Transaction> validTransactions;

  for(auto transaction : transactionPool) {
    if(transaction.verifyTransaction()) {
      validTransactions.push_back(transaction);
      transactionTree.push_back(getHash(transaction.getTransactionString()));
    }
  }
  cout<<"==========\ttransactions validated"<<validTransactions.size()<<"\n\n";

  transactionPool.clear();
  transactionPool = validTransactions;
  return transactionTree.getRootHash();
}

void completePendingTransactions(vector<Transaction> &transactionPool) {
  for(auto transaction : transactionPool) {
    transaction.completeTransaction();
  }
}
