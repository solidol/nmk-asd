#include <iostream>
using namespace std;

// Структура ветки
struct Branch {
    int Data; // Поле даних
    Branch* LeftBranch; // Вказівники на ліву та праву гілку
    Branch* RightBranch;
};

// Функція внесення даних
void Add(char aData, Branch*& aBranch) {
    if (!aBranch) { // Якщо гілки не існує, створюємо її та додаємо дані
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->LeftBranch = nullptr;
        aBranch->RightBranch = nullptr;
        return;
    } else { // В іншому випадку порівнюємо дані
        if (aData < aBranch->Data) {
            Add(aData, aBranch->LeftBranch);
        } else {
            Add(aData, aBranch->RightBranch);
        }
    }
}

// Функція виведення дерева
void Print(Branch* aBranch, int level = 0) {
    if (!aBranch) return; // Якщо гілки не існує, виходимо
    Print(aBranch->RightBranch, level + 1); // Виводимо праву гілку
    for (int i = 0; i < level; i++) cout << "  "; // Відступи для красивого відображення
    cout << aBranch->Data << endl; // Виводимо дані
    Print(aBranch->LeftBranch, level + 1); // Виводимо ліву гілку
}

// Функція для звільнення пам'яті, включаючи всі гілки
void FreeTree(Branch* aBranch) {
    if (!aBranch) return;
    FreeTree(aBranch->LeftBranch);
    FreeTree(aBranch->RightBranch);
    delete aBranch;
}

int main() {
    Branch* Root = nullptr;
    int s[] = {10, 6, 8, 14, 5, 2, 11, 13, 7, 15, 4, 3, 0, 16, 1, 17, 18, 12, 19};

    for (int i = 0; i < 20; i++) {
        Add(s[i], Root);
    }

    Print(Root);
    FreeTree(Root);

    cin.get();
    return 0;
}