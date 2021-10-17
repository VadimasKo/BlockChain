#include <string>

#include "src/generateRandom/GenerateRandom.hpp"

using namespace std;


class User {
  private:
    string secretKey; 
  public:
    User(string uid) {
      secretKey = getRandomString(64) + uid;
      publicKey = getRandomString(64) + uid;
    }
    string publicKey;
    string signMessage(string messages) {
      return messages + secretKey;
    }
};
