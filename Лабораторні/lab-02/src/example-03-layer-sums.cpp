#include <iostream>

int main() {
    int layers, rows, cols;
    if (!(std::cin >> layers >> rows >> cols) ||
        layers <= 0 || rows <= 0 || cols <= 0) {
        std::cerr << "Потрібні додатні розміри масиву.\n";
        return 1;
    }

    int*** a = new int**[layers];
    for (int i = 0; i < layers; ++i) {
        a[i] = new int*[rows];
        for (int j = 0; j < rows; ++j)
            a[i][j] = new int[cols];
    }

    for (int i = 0; i < layers; ++i) {
        long long sum = 0;
        for (int j = 0; j < rows; ++j)
            for (int k = 0; k < cols; ++k) {
                a[i][j][k] = i + 1;
                sum += a[i][j][k];
            }
        std::cout << "Шар " << i << ": " << sum << '\n';
    }

    for (int i = 0; i < layers; ++i) {
        for (int j = 0; j < rows; ++j)
            delete[] a[i][j];
        delete[] a[i];
    }
    delete[] a;
}
