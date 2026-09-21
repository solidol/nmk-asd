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
            a[i][j] = i + j + 1;

    for (int i = 0; i < rows; ++i) {
        long long sum = 0;
        for (int j = 0; j < cols; ++j)
            sum += a[i][j];
        std::cout << "Рядок " << i << ": " << sum << '\n';
    }

    for (int i = 0; i < rows; ++i)
        delete[] a[i];
    delete[] a;
}
