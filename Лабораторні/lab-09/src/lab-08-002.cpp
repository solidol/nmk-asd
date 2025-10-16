
#include <iostream>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    cout << "mt19937 numbers: ";
    for (int i = 0; i < 10; i++)
        cout << dist(gen) << " ";
    cout << endl;

    return 0;
}
