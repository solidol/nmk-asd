#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void bubbleSort(int * , int); // прототип функції сортування бульбашкою

int main(int argc, char * argv[]) {
  srand(time(NULL));
  setlocale(LC_ALL, "rus");
  cout << " Введіть розмір масиву: ";
  int size_array; // довжина масиву
  cin >> size_array;

  int * sorted_array = new int[size_array]; // одновимірний динамічний масив
  for (int counter = 0; counter < size_array; counter++) {
    sorted_array[counter] = rand() % 100; // заповнюємо масив випадковими числами
    cout << setw(2) << sorted_array[counter] << "  "; // вивід масиву на екран
  }
  cout << "\n\n";

  bubbleSort(sorted_array, size_array); // виклик функції сортування бульбашкою

  for (int counter = 0; counter < size_array; counter++) {
    cout << setw(2) << sorted_array[counter] << "  "; // друк відсортованого масиву
  }
  cout << "\n";

  system("pause");
  return 0;
}

void bubbleSort(int * arrayPtr, int length_array) // сортування бульбашкою
{
  int temp = 0; // тимчасова змінна для зберігання елемента масиву
  bool exit = false; // больова змінна для виходу з циклу, якщо масив відсортований
  while (!exit) // поки маса не впорядкований
  {
    exit = true;
    for (int int_counter = 0; int_counter < (length_array - 1); int_counter++) // внутрішній цикл
      // сортування бульбашкою по зростанню - знак >
      // сортування бульбашкою по спадаючій - знак <
      if (arrayPtr[int_counter] > arrayPtr[int_counter + 1]) // порівнюємо два сусідні елементи
    {
      // виконуємо перестановку елементів масиву
      temp = arrayPtr[int_counter];
      arrayPtr[int_counter] = arrayPtr[int_counter + 1];
      arrayPtr[int_counter + 1] = temp;
      exit = false; // на черговій ітерації була проведена перестановка елементів    
    }
  }
}