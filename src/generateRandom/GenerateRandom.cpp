#include <string>
#include <random>

using namespace std;


class RandInt {
  private:
    random_device rd;
    mt19937 mt;
    uniform_int_distribution<int> dist;
  public:
    RandInt(int low, int high) : mt{rd()}, dist{low, high} {}
    int operator ()() {return dist(mt);}
};


const string alphaNumeric =
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
RandInt randomChar {0, alphaNumeric.length()};


string getRandomString(int size) {
  string randomString = "";
  for(int i = 0; i<size; i++) {
    randomString.push_back(alphaNumeric[randomChar()]);
  }
  return randomString;
}
