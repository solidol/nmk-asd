#include <iostream>
#include <ctime>

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
    const int size = 1000000;  // Розмір масиву
    int arr[size];

    // Заповнення масиву випадковими числами
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000000;
    }

    int target = arr[rand() % size];  // Випадковий елемент для пошуку

    // Вимірювання часу пошуку
    clock_t start_time = clock();
    int result = linearSearch(arr, size, target);
    clock_t end_time = clock();

    // Виведення результатів
    if (result != -1) {
        cout << "Елемент " << target << " знайдено за індексом " << result << endl;
    } else {
        cout << "Елемент " << target << " не знайдено в масиві." << endl;
    }

    // Виведення часу виконання пошуку
    double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Час пошуку: " << elapsed_time << " секунд." << endl;

    return 0;
}
