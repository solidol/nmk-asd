#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для представлення елементу хеш-таблиці
struct HTItem {
    char *value;
    struct HTItem *next;
};

// Структура для представлення хеш-таблиці
struct HT {
    unsigned long CAPACITY;
    struct HTItem **rows;
};

// Функція для створення хеш-таблиці
struct HT* createHashTable(unsigned long capacity) {
    struct HT *table = (struct HT*)malloc(sizeof(struct HT));
    table->CAPACITY = capacity;
    table->rows = (struct HTItem**)malloc(capacity * sizeof(struct HTItem*));

    for (unsigned long i = 0; i < capacity; i++) {
        table->rows[i] = NULL;
    }

    return table;
}

// Функція для простого хешування рядка
unsigned long simpleHash(char *str, unsigned long capacity) {
    unsigned long i = 0;
    while (*str) {
        i += *str;
        str++;
    }
    return i % capacity;
}

// Функція для додавання рядка в таблицю
void insert(struct HT *table, char *value) {
    unsigned long key = simpleHash(value, table->CAPACITY);
    struct HTItem *newItem = (struct HTItem*)malloc(sizeof(struct HTItem));
    newItem->value = strdup(value);
    newItem->next = table->rows[key];
    table->rows[key] = newItem;
}

// Функція для друку таблиці
void print(struct HT *table) {
    for (unsigned long i = 0; i < table->CAPACITY; i++) {
        struct HTItem *current = table->rows[i];
        while (current != NULL) {
            printf("%lx\t%s\n", i, current->value);
            current = current->next;
        }
    }
}

// Функція для пошуку в таблиці
struct HTItem* search(struct HT *table, char *key) {
    unsigned long sindex = simpleHash(key, table->CAPACITY);
    struct HTItem *current = table->rows[sindex];
    while (current != NULL) {
        if (strcmp(current->value, key) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    struct HT *table = createHashTable(1024 * 64);

    insert(table, "df agdf dsfhbsdg hbsdg dfagdfgadfgvafgdfhbd");
    insert(table, "dfg dfgdf agdh shbggadfgvafgdfhbd");
    insert(table, "df ag3333g dfagdfgadfgv555 6 6765 45afgdfhbd");
    insert(table, "jh kvjdf axfb dgfnbxfgn dfdfgadfgvafgdfhbd");
    insert(table, "hg hg6565 df agdf dsfhbsdg hbsdg dfagdfgadfgvafgdfhbd");
    insert(table, "df agd65832625 325 4654  000fgvafgdfhbd");
    insert(table, "df agdffxg vbk,yfu hsfd gshggdfgadfgvafgdfhbd");
    insert(table, "3243 435df agdf dsfhbsdg hbsdg dfag dfj ydgfchsdgfaesgrgsgvafgdfhbd");
    insert(table, "h jkgfhdf agdf dsfhbsdg hafgdfhbd");
    insert(table, "906 3 5 u7df agdf dsfhsf hgasehb bsdg hbsdg dfagd7 djdhghb s5 shstrhbs fgadfgvafgdfhbd");
    insert(table, "");
    insert(table, "a");

    print(table);
    printf("%lx\n", (unsigned long)search(table, "a"));
    printf("%lx\n", (unsigned long)search(table, "asd"));
    printf("%lx\n", (unsigned long)search(table, "h jkgfhdf agdf dsfhbsdg hafgdfhbd"));

    // Виведення пам'яті та завершення роботи
    for (unsigned long i = 0; i < table->CAPACITY; i++) {
        struct HTItem *current = table->rows[i];
        while (current != NULL) {
            free(current->value);
            struct HTItem *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(table->rows);
    free(table);

    return 0;
}
