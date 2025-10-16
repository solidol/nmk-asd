
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(nullptr));
    cout << "rand() numbers: ";
    for (int i = 0; i < 10; i++)
        cout << rand() % 100 << " ";
    cout << endl;
    return 0;
}
