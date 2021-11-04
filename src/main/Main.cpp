#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

#include "../block/Block.hpp"
#include "../generateHash/GenerateHash.hpp"
#include "../generateRandom/GenerateRandom.hpp"
#include "../merkelTree/MerkelTree.hpp"
#include "../transactions/TransactionPool.hpp"
#include "../transactions/Transactions.hpp"
#include "../user/User.hpp"

using namespace std;

Block generateGenesisBlock(vector<User> &users);
void generateRandomTransactions(vector<Transaction> &transactionPool,  vector<User> &users);
long int mineWorkProof(string lastBlock, int dificulty);

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
      MerkelTree transactionTree;
      for(auto transaction : transactionPool) {
        transactionTree.push_back(getHash(transaction.getTransactionString()));
      }
      transactionPool.clear();
      Block newBlock(proof, transactionTree.getRootHash(), lastBlockHash);
      lastBlockHash = getHash(newBlock.blockToString());
      blockChain.insert({lastBlockHash, newBlock});
  }
}


Block generateGenesisBlock(vector<User> &users) {
  User genesisUser(10*1000);
  vector<Transaction> genesisTransactions;
  MerkelTree transactionTree;
  
  for(int i = 0; i < 1000; i++) {
    users.push_back(User(0));
    User* receiver = &users[i];
    genesisTransactions.push_back(Transaction(&genesisUser, receiver, 100.0));
  }
  cout<<"======== 1000 Random Users Created======"<<endl<<endl;
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
  cout<<"======== 100 Random Transactions Created ======"<<endl;
}

long int mineWorkProof(string lastBlock, int dificulty) {
  string target = string(dificulty,'0');
  for(long int i = 0; true; i++) {
    string hash = getHash(lastBlock + to_string(i));
    if(hash.substr(0,dificulty) == target) return i;
  }
}