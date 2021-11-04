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

Block generateGenesisBlock(vector<User> &users);
void generateRandomTransactions(vector<Transaction> &transactionPool,  vector<User> &users);
long int mineWorkProof(string lastBlock, int dificulty);
string getRootHash(vector<Transaction> &transactionPool);
void completePendingTransactions(vector<Transaction> &transactionPool);

int main() {
  unordered_map<string, Block> blockChain;
  vector<User> users;
  string lastBlockHash = "";
  users.reserve(1000);

  blockChain.insert({"Genesis", generateGenesisBlock(users)});
  lastBlockHash="Genesis";
  while(true) { 
      vector<Transaction> transactionPool;
      transactionPool.reserve(150);

      generateRandomTransactions(transactionPool, users);
      long int proof = mineWorkProof(blockChain[lastBlockHash].blockToString(), blockChain[lastBlockHash].getDificulty());

      string rootHash = getRootHash(transactionPool);
      Block newBlock(proof, rootHash, lastBlockHash);
      lastBlockHash = getHash(newBlock.blockToString());
      blockChain.insert({ lastBlockHash, newBlock });
      completePendingTransactions(transactionPool);
      transactionPool.clear();
  }
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
  cout<<"======== 1000 Random Users Created\n\n";
  for(auto transaction : genesisTransactions) {
    transactionTree.push_back(getHash(transaction.getTransactionString()));
  }
  return Block(transactionTree.getRootHash(), "");
}

void generateRandomTransactions( vector<Transaction> &transactionPool,  vector<User> &users) {
  for(int i = 0; i<100; i++) {
    Transaction newTransaction(
      &users[getRandomUser()],
      &users[getRandomUser()],
      getRandomSum()*1.0
    );
    transactionPool.push_back(newTransaction);
  }
}

long int mineWorkProof(string lastBlock, int dificulty) {
  string target = string(dificulty,'0');
  for(long int i = 0; true; i++) {
    string hash = getHash(lastBlock + to_string(i));
    if(hash.substr(0,dificulty) == target) return i;
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
  cout<<"======== transactions validated"<<validTransactions.size()<<"\n\n";

  transactionPool.clear();
  transactionPool = validTransactions;
  return transactionTree.getRootHash();
}

void completePendingTransactions(vector<Transaction> &transactionPool) {
  for(auto transaction : transactionPool) {
    transaction.completeTransaction();
  }
}