
#include <iostream>
#include <sstream>
#include <set>
#include <string>
using namespace std;

double jaccardSimilarity(const string &text1, const string &text2) {
    set<string> set1, set2, intersection, uni;
    string word;

    istringstream iss1(text1), iss2(text2);
    while (iss1 >> word) set1.insert(word);
    while (iss2 >> word) set2.insert(word);

    for (auto &w : set1)
        if (set2.count(w)) intersection.insert(w);

    uni = set1;
    uni.insert(set2.begin(), set2.end());

    return (double)intersection.size() / (double)uni.size();
}

int main() {
    string t1 = "this is a simple text";
    string t2 = "this text is simple and short";
    cout << "Jaccard similarity: " << jaccardSimilarity(t1, t2) << endl;
    return 0;
}
