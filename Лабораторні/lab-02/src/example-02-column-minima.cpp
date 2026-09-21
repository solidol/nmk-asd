#include <iostream>

int main() {
    int rows, cols;
    if (!(std::cin >> rows >> cols) || rows <= 0 || cols <= 0) {
        std::cerr << "Потрібні додатні розміри матриці.\n";
        return 1;
    }

    int** a = new int*[rows];
    for (int i = 0; i < rows; ++i)
        a[i] = new int[cols];

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            a[i][j] = 3 * i - j;

    for (int j = 0; j < cols; ++j) {
        int minimum = a[0][j];
        for (int i = 1; i < rows; ++i)
            if (a[i][j] < minimum) minimum = a[i][j];
        std::cout << "Стовпець " << j << ": " << minimum << '\n';
    }

    for (int i = 0; i < rows; ++i)
        delete[] a[i];
    delete[] a;
}
