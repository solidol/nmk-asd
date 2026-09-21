#include <iostream>
#include <limits>

int main() {
    int n;
    std::cout << "Array size: ";
    if (!(std::cin >> n) || n <= 0 || n > std::numeric_limits<int>::max() / 2) {
        std::cerr << "Enter a positive array size up to INT_MAX / 2.\n";
        return 1;
    }

    int* a = new int[n];
    for (int i = 0; i < n; ++i)
        *(a + i) = 2 * i + 1;

    for (const int* p = a; p != a + n; ++p)
        std::cout << *p << ' ';
    std::cout << '\n';

    delete[] a;
}
