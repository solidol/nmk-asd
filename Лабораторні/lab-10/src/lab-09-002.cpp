
#include <iostream>
#include <string>
using namespace std;

unsigned long long rollingHash(const string &s, int p = 31, int m = 1e9 + 9) {
    unsigned long long hash = 0, p_pow = 1;
    for (char c : s) {
        hash = (hash + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash;
}

int main() {
    string text = "hello";
    cout << "Rolling hash: " << rollingHash(text) << endl;
    return 0;
}
