// Програма лінійного пошуку в тексті
#include <iostream>
#include <string>

using namespace std;

int linearSearch(const string& text, const string& target) {
    for (int i = 0; i < text.length(); i++) {
        if (text.substr(i, target.length()) == target) {
            return i; // Повертаємо позицію першого входження слова
        }
    }
    return -1; // Повертаємо -1, якщо слово не знайдено
}

int main() {
    string text = "Це приклад тексту для лінійного пошуку слова.";
    string word;

    cout << "Введіть слово, яке потрібно знайти: ";
    cin >> word;

    int result = linearSearch(text, word);

    if (result != -1) {
        cout << "Слово '" << word << "' знайдено в тексті за позицією " << result << endl;
    } else {
        cout << "Слово '" << word << "' не знайдено в тексті." << endl;
    }

    return 0;
}
