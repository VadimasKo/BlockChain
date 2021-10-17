#include <string>
#include <vector>

#include "MerkleTree.hpp"
#include "../generateHash/GenerateHash.hpp"

using namespace std;


void concatPairs (vector<string> &pairs) {
    vector<string> newPairs;
    for(int i = pairs.size()-1; i > 0; i-=2) {
        newPairs.insert(newPairs.begin(),pairs[i-1] + pairs[i]);
    }
    pairs = newPairs;
}


void MerkleTree::push_back(string hash) {
    hashes.push_back(hash);
}

string MerkleTree::getRootHash() {
    if(rootHash != "") return rootHash;

    if(hashes.size() % 2 == 1) hashes.push_back(hashes[hashes.size() - 1]);
    while(hashes.size() != 1) {
      concatPairs(hashes);
      for(int i = 0; i < hashes.size(); i++) {
        hashes[i] = getHash(hashes[i]);
      }
    }
    rootHash = hashes[0];
    return rootHash;
}
