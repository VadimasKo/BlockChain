#include <random>
#include <string>

#include "GenerateRandom.hpp"

using namespace std;
class RandomInt{
    private:
        random_device                   rd;
        mt19937                         mt;
        uniform_int_distribution<int> dist;
    public:
        RandomInt(int floor, int ceiling) : mt{rd()}, dist{floor, ceiling} {}
        int operator ()() { return dist(mt); }
};

const string alphaNum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
RandomInt randomChar {0, 61};


string getRandomString(unsigned int size) {
    string randomString = "";
    for(int i = 0; i < size; i++) {
        randomString.push_back(alphaNum[randomChar()]);
    }
    return randomString;
}