// Програма пошуку в тексті за алгоритмом КМП
#include <iostream>
#include <cstring>

using namespace std;

// Генерує префікс-функцію для паттерну
void computePrefixFunction(const char* pattern, int m, int* prefix) {
    int k = 0;
    prefix[0] = 0;

    for (int q = 1; q < m; q++) {
        while (k > 0 && pattern[q] != pattern[k]) {
            k = prefix[k - 1];
        }

        if (pattern[q] == pattern[k]) {
            k++;
        }

        prefix[q] = k;
    }
}

// Виконує пошук за алгоритмом KMP
void searchKMP(const char* text, const char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int* prefix = new int[m];
    computePrefixFunction(pattern, m, prefix);

    int q = 0;

    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i]) {
            q = prefix[q - 1];
        }

        if (pattern[q] == text[i]) {
            q++;
        }

        if (q == m) {
            cout << "Знайдено входження паттерну з позиції " << i - m + 1 << endl;
            q = prefix[q - 1];
        }
    }

    delete[] prefix;
}

int main() {
    const char* text = "Це приклад тексту для пошуку паттерну в тексті. Паттерн - це";
    const char* pattern = "Паттерн";

    cout << "Текст: " << text << endl;
    cout << "Паттерн: " << pattern << endl;

    searchKMP(text, pattern);

    return 0;
}
