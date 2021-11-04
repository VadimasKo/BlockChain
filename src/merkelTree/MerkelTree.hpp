#pragma once
#include <string>
#include <vector>

using namespace std;

class MerkelTree {
    private:
        string rootHash = "";
        vector<string> hashes;
    public:
        string getRootHash();
        void push_back(string hash);
};