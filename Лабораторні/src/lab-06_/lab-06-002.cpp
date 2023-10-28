#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
 
void insertionSort(int *, int); // прототип функції сортування вставками
 
int main(int argc, char* argv[])
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    cout << " Введіть розмір масиву: ";
    int size_array; // довжина масиву
    cin >> size_array;
 
    int *sorted_array = new int [size_array]; // одновимірний динамічний масив
    for (int counter = 0; counter < size_array; counter++)
    {
        sorted_array[counter] = rand() % 100; // заповнюємо масив випадковими числами
        cout << setw(2) << sorted_array[counter] << "  "; // висновок масиву на екран
    }
    cout << "n";
 
    insertionSort(sorted_array, size_array); // виклик функції сортування вставками
 
    for (int counter = 0; counter < size_array; counter++)
    {
        cout << setw(2) << sorted_array[counter] << "  "; // друк відсортованого масиву
    }
    cout << "n";
    delete [] sorted_array; // вивільняє пам'ять
    system("pause");
    return 0;
}
 
void insertionSort(int *arrayPtr, int length) // сортування вставками
{
    int temp, // тимчасова змінна для зберігання значення елемента сортованого масиву
        item; // індекс попереднього елемента
    for (int counter = 1; counter < length; counter++)
    {
        temp = arrayPtr[counter]; // инициализируем тимчасову змінну поточним значенням елемента масиву
        item = counter-1; // запам'ятовуємо індекс попереднього елемента масиву
        while(item >= 0 && arrayPtr[item] > temp) // поки індекси не дорівнює 0 і попередній елемент масиву більше поточного
        {
            arrayPtr[item + 1] = arrayPtr[item]; // перестановка елементів масиву
            arrayPtr[item] = temp;
            item--;
        }
    }
}
