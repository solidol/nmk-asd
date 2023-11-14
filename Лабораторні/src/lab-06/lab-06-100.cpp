#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

// Функція для пошуку елементу в масиві
int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;  // Повертає індекс, якщо елемент знайдено
        }
    }
    return -1;  // Повертає -1, якщо елемент не знайдено
}

int main() {
    const int size = 200000;  // Розмір масиву
    int arr[size];

    // Заповнення масиву випадковими числами
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100000;
    }

    int target = arr[rand() % size];  // Випадковий елемент для пошуку

    // Вимірювання часу пошуку
    auto start_time = chrono::high_resolution_clock::now();
    int result = linearSearch(arr, size, target);
    auto end_time = chrono::high_resolution_clock::now();

    // Виведення результатів
    if (result != -1) {
        cout << "Елемент " << target << " знайдено за індексом " << result << endl;
    }
    else {
        cout << "Елемент " << target << " не знайдено в масиві." << endl;
    }

    // Виведення часу виконання пошуку
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Час виконання: " << duration.count() << " мікросекунд." << endl;

    return 0;
}