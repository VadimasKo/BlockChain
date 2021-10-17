#include <iostream>

#include "../generateHash/GenerateHash.hpp"
#include "../generateRandom/GenerateRandom.hpp"
#include "../merkleTree/MerkleTree.hpp"

using namespace std;


int main() {
  MerkleTree test;
  test.push_back("123");
  test.push_back("4s56");
  test.push_back("789");
  test.push_back("ABC");
  cout<<test.getRootHash();
}