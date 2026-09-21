#include <iostream>

int main() {
    int x = 10;
    int* px = &x;

    std::cout << "Before: x = " << x << ", *px = " << *px << '\n';
    *px *= 2;
    std::cout << "After: x = " << x << ", *px = " << *px << '\n';
}
