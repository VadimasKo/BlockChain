#include <iostream>
#include <string>

#include "../generateHash/GenerateHash.hpp"
#include "../generateRandom/GenerateRandom.hpp"
#include "../merkleTree/MerkleTree.hpp"
#include "../transactions/TransactionPool.hpp"
#include "../transactions/Transactions.hpp"
#include "../user/User.hpp"

using namespace std;


int main() {
  // MerkleTree test;
  // test.push_back("123");
  // test.push_back("4s56");
  // test.push_back("789");
  // test.push_back("ABC");
  // cout<<test.getRootHash();
  User testUser1(2.5);
  User testUser2(1.5);
  TransactionPool testPool;
  testPool.addNewTransaction(Transaction(&testUser1, &testUser2, 1.0));
  testPool.addNewTransaction(Transaction(&testUser1, &testUser2, 1.0));
  vector<Transaction> partOfPool = testPool.getPartOfTransactions(2);
  for (Transaction transaction : partOfPool) {
    cout<<transaction.getTransactionString()<<endl;
  }
}