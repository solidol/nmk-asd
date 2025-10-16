
#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>
using namespace std;

string sha256(const string &input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)input.c_str(), input.size(), hash);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    return ss.str();
}

int main() {
    string text = "Hello world";
    cout << "SHA-256: " << sha256(text) << endl;
    return 0;
}
