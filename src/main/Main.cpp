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

void generateGenesisBlock(vector<User> &users);

int main() {
  // unordered_map<string, Block> blockChain;
  TransactionPool TransactionPool;
  vector<User> users;
  generateGenesisBlock(users);

  // blockChain.insert({"Genesis", generateGenesisBlock(users)});
}

void generateGenesisBlock(vector<User> &users) {
  User genesisUser(10*1000);
  vector<Transaction> genesisTransactions;
  MerkleTree transactionTree;
  
  for(int i = 0; i < 10; i++) {
    cout<<i<<endl;
    users.push_back(User(0));
    User* receiver = &users[i];
    genesisTransactions.push_back(Transaction(&genesisUser, receiver, 100.0));
  }
  cout<<endl<<endl;
  for(int i = 0; i < genesisTransactions.size(); i++) {
    cout<<i<<endl;
    cout<<genesisTransactions[i].getTransactionString()<<endl;
    // transactionTree.push_back(getHash(transaction.getTransactionString()));
  }
  // return Block(transactionTree.getRootHash());
}