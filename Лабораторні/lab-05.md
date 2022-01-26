[Перелік усіх робіт](README.md)

# Обробка зв'язного списку

## Мета роботи 

Отримати навички роботи з типами даних в мовах програмування C та С++

## Обладнання

Персональний комп’ютер, Visual Studio 2008 або інша середа розробки для мови C++

## Теоретичні відомості

Однозв'язний список - це динамічна структура даних, що складається з вузлів. Кожен вузол буде мати якесь значення (я використовуватиму рядок) і покажчик на наступний вузол.

### Реалізація вузла

У цьому вузлі є:

* Значення, яке буде ставити користувач
* Вказівник на наступний елемент (за замовчуванням nullptr)
* Конструктор


```cpp
struct Node {
  string val;
  Node* next;
  Node(string _val) : val(_val), next(nullptr){}
};
```

### Реалізація однозв'язкового списку

Базові функції списку:

* Покажчик на перший вузол
* Покажчик на останній вузол
* Конструктор
* Функція додавання елемента до кінця списку
* Функція друку всього списку
* Функція пошуку вузла у списку за заданим значенням
* Функція видалення вузла за заданим значенням

```cpp
#include <iostream>
using namespace std;

struct Node {
    string val;
    Node* next;

    Node(string _val) : val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(string _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    Node* find(string _val) {
        Node* p = first;
        while (p && p->val != _val) p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove(string _val) {
        if (is_empty()) return;
        if (first->val == _val) {
            remove_first();
            return;
        }
        else if (last->val == _val) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    Node* operator[] (const int index) {
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
};

int main()
{
    list l;
    cout << l.is_empty() << endl;
    l.push_back("3");
    l.push_back("123");
    l.push_back("8");
    l.print();
    cout << l.is_empty() << endl;
    l.remove("123");
    l.print();
    l.push_back("1234");
    l.remove_first();
    l.print();
    l.remove_last();
    l.print();
    cout << l[0]->val << endl;
    return 0;
}
```

## Хід роботи

1. Завантажити Visual Studio 2008. Знайдіть на робочому столі ярлик з Visual Studio 2008 або Пуск → Всі програми→ Microsoft → Microsoft Visual Studio 2008.

2. Створити новий проект «Visual C++ (консольное приложение Win32)». Файл → Cтворити → Проект, тип проекту «Консольное приложение Win32».

3. Перевірити роботу прикладів, пояснити їх роботу
    
    [Приклад 1](../Приклади/lab-02-001.cpp)

4. Змінити приклад настуним чином:
    * у якості даних у вузол записувати ПІБ людини та її вік
    * реалізувати функцію друку всіх записів списку для віку 25 та вище

5. Скласти звіт про роботу, у звіт додати код програми та відповісти на контрольні питання

## Контрольні питання

1. Дайте характеристику типам даних в мові програмування С
2. Охарактеризуйте арифметичні операції мові програмування С
3. Охарактеризуйте логічні операції мові програмування С
4. Охарактеризуйте пріоритет операцій мови програмування С

## Довідники та додаткові матеріали

1. [C++ List: How To Add, Assign, Delete List In C++](https://appdividend.com/2022/01/18/cpp-list/)
1. [Списки в C++. Односвязный список](https://otus.ru/nest/post/911/)
1. [Список list в С++: полный материал](https://codelessons.ru/cplusplus/spisok-list-v-s-polnyj-material.html)
