// Алгоритм Р. Боуера и Д. Мура

#include <iostream>
#include <cstring>

using namespace std;

const int NO_OF_CHARS = 256;

// Функція для заповнення таблиці зсувів
void computeBadCharHeuristic(const char* pattern, int m, int badchar[NO_OF_CHARS]) {
    for (int i = 0; i < NO_OF_CHARS; i++) {
        badchar[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        badchar[(int)pattern[i]] = i;
    }
}

// Функція для виконання пошуку за алгоритмом BM
void searchBM(const char* text, const char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int badchar[NO_OF_CHARS];

    computeBadCharHeuristic(pattern, m, badchar);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            cout << "Знайдено входження паттерну з позиції " << s << endl;

            if (s + m < n) {
                s += m - badchar[text[s + m]];
            } else {
                s += 1;
            }
        } else {
            s += max(1, j - badchar[text[s + j]]);
        }
    }
}

int main() {
    const char* text = "Це приклад тексту для пошуку паттерну в тексті. Паттерн - це";
    const char* pattern = "Паттерн";

    cout << "Текст: " << text << endl;
    cout << "Паттерн: " << pattern << endl;

    searchBM(text, pattern);

    return 0;
}
