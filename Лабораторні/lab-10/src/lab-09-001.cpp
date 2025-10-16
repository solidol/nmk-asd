
#include <iostream>
#include <string>
using namespace std;

unsigned int simpleHash(const string &s) {
    unsigned int hash = 0;
    for (char c : s) hash = (hash * 31 + c) % 100000;
    return hash;
}

int main() {
    string text = "Hello world";
    cout << "Simple hash: " << simpleHash(text) << endl;
    return 0;
}
