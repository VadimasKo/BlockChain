#include <string>

#include "GenerateHash.hpp"


const int hashSize = 32;

string pipeCommand(string command) {
    FILE *pipe = popen(command.c_str(), "r");
    string result;
    char line[hashSize];
 
    while (fgets(line, hashSize, pipe)) {
        result += line;
    }
    pclose(pipe);
    return result;
} 

string getHash(string input) {
    string command = "echo -n" + input + " | md5sum";
    // string command = "./HasGenerator + input";
    string hash = pipeCommand(command);

    //rm garbage at the end md5sum
    hash.pop_back();
    hash.pop_back();
    hash.pop_back();
    hash.pop_back();

    return hash;
}
