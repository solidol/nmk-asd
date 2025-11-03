#include <iostream>

using namespace std;

// Клас для представлення елементу хеш-таблиці
class HTItem {
public:
    string value;
    HTItem* next;
    HTItem(string val) {
        value = val;
        next = nullptr;
    }
    int searchNext(string key) {
        // Функція пошуку наступного елементу
    }
};

// Клас для представлення хеш-таблиці
class HT {
private:
    const unsigned long CAPACITY = 1024 * 64; // Розмір хеш-таблиці
public:
    HTItem** rows;
    // Конструктор хеш-таблиці
    HT() {
        rows = new HTItem* [CAPACITY];
        for (unsigned long i = 0; i < CAPACITY; i++) {
            rows[i] = nullptr;
        }
    }
    // функція простого хешування рядку
    unsigned long simpleHash(string str) {
        unsigned long i = 0;
        for (int j = 0; str[j]; j++)
            i += str[j];
        return i % CAPACITY;
    }
    // функція додавання рядку в таблицю
    void insert(string value) {
        unsigned long key = simpleHash(value);
        rows[key] = new HTItem(value);
    }
    // функція друку таблиці
    void print() {
        for (unsigned long i = 0; i < CAPACITY; i++) {
            if (rows[i] != nullptr) {
                cout << hex;
                cout << i << "\t" << rows[i]->value << endl;
            }
        }
    }
    // функція пошуку в таблиці
    HTItem* search(string key) {
        unsigned long sindex = simpleHash(key);
        if (rows[sindex] != nullptr) {
            return rows[sindex];
        }
        else {
            return nullptr;
        }
    }
};

int main()
{
    HT table;
    table.insert("df agdf dsfhbsdg hbsdg dfagdfgadfgvafgdfhbd");
    table.insert("dfg dfgdf agdh shbggadfgvafgdfhbd");
    table.insert("df ag3333g dfagdfgadfgv555 6 6765 45afgdfhbd");
    table.insert("jh kvjdf axfb dgfnbxfgn dfdfgadfgvafgdfhbd");
    table.insert("hg hg6565 df agdf dsfhbsdg hbsdg dfagdfgadfgvafgdfhbd");
    table.insert("df agd65832625 325 4654  000fgvafgdfhbd");
    table.insert("df agdffxg vbk,yfu hsfd gshggdfgadfgvafgdfhbd");
    table.insert("3243 435df agdf dsfhbsdg hbsdg dfag dfj ydgfchsdgfaesgrgsgvafgdfhbd");
    table.insert("h jkgfhdf agdf dsfhbsdg hafgdfhbd");
    table.insert("906 3 5 u7df agdf dsfhsf hgasehb bsdg hbsdg dfagd7 djdhghb s5 shstrhbs fgadfgvafgdfhbd");
    table.insert("");
    table.insert("a");
    table.print();
    cout << hex;
    cout << table.search("a") << endl;
    cout << table.search("asd") << endl;
    cout << table.search("h jkgfhdf agdf dsfhbsdg hafgdfhbd") << endl;
}