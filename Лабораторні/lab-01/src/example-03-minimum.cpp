#include <iostream>

int main() {
    int n;
    std::cout << "Array size: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Enter a positive array size.\n";
        return 1;
    }

    int* a = new int[n];
    std::cout << "Enter " << n << " integers: ";
    for (int* p = a; p != a + n; ++p) {
        if (!(std::cin >> *p)) {
            std::cerr << "Invalid input.\n";
            delete[] a;
            return 1;
        }
    }

    int minimum = *a;
    for (const int* p = a + 1; p != a + n; ++p)
        if (*p < minimum) minimum = *p;

    std::cout << "Minimum: " << minimum << '\n';
    delete[] a;
}
