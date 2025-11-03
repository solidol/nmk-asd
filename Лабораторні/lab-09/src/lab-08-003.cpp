
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

void fisherYatesShuffle(vector<int>& arr) {
    random_device rd;
    mt19937 gen(rd());
    for (int i = arr.size() - 1; i > 0; i--) {
        uniform_int_distribution<> dist(0, i);
        int j = dist(gen);
        swap(arr[i], arr[j]);
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fisherYatesShuffle(arr);
    cout << "Shuffled array: ";
    for (int n : arr) cout << n << " ";
    cout << endl;
    return 0;
}
