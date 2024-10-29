#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
 
void choicesSort(int*, int); // прототип функції сортування вибором
 
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
    cout << "\n\n";
 
    choicesSort(sorted_array, size_array); // виклик функції сортування вибором
 
    for (int counter = 0; counter < size_array; counter++)
    {
        cout << setw(2) << sorted_array[counter] << "  "; // друк відсортованого масиву
    }
    cout << "\n";
    delete [] sorted_array; // вивільняє пам'ять
    system("pause");
    return 0;
}
 
void choicesSort(int* arrayPtr, int length_array) // сортування вибором
{
    for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
    {
        int temp = arrayPtr[0]; // тимчасова змінна для зберігання значення перестановки
        for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
        {
            if (arrayPtr[repeat_counter] > arrayPtr[element_counter])
            {
                temp = arrayPtr[repeat_counter];
                arrayPtr[repeat_counter] = arrayPtr[element_counter];
                arrayPtr[element_counter] = temp;
            }
        }
    }
}
