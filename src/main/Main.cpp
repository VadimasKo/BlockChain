#include <iostream>

#include "../generateHash/GenerateHash.hpp"
#include "../generateRandom/GenerateRandom.hpp"

using namespace std;


int main() {
  cout<<getHash("abc")<<endl;
  cout<<getHash("abc")<<endl;
  cout<<getHash("bbc")<<endl;
  string a = getHash("bbc");
  cout<<a.size();
}