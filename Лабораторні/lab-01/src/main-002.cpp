#include <iostream>
#include <cstdlib>  // Для функції rand()
#include <ctime>    // Для функції time()

int main() {
    // Ініціалізуємо генератор випадкових чисел
    std::srand(std::time(nullptr));

    int size;

    std::cout << "Введіть розмір масиву: ";
    std::cin >> size;

    // Створюємо одновимірний динамічний масив
    int* array = new int[size];

    // Заповнюємо масив випадковими числами
    for (int i = 0; i < size; ++i) {
        array[i] = std::rand() % 100;  // Випадкові числа від 0 до 99
    }

    // Виводимо масив на екран
    std::cout << "Згенерований масив:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    // Звільняємо динамічний масив
    delete[] array;

    return 0;
}
