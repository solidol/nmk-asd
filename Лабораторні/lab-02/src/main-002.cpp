#include <iostream>
#include <cstdlib>  // Для функції rand()
#include <ctime>    // Для функції time()

int main() {
    // Ініціалізуємо генератор випадкових чисел
    std::srand(std::time(nullptr));

    int rows, cols;

    std::cout << "Введіть кількість рядків: ";
    std::cin >> rows;
    std::cout << "Введіть кількість стовпців: ";
    std::cin >> cols;

    // Створюємо двовимірний динамічний масив
    int** array = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    // Заповнюємо масив випадковими числами
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = std::rand() % 100;  // Випадкові числа від 0 до 99
        }
    }

    // Виводимо масив на екран
    std::cout << "Згенерований масив:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Видаляємо динамічний масив
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
