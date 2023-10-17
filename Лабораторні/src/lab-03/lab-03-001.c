#include <stdio.h>
#include <stdlib.h>

// Структура для вузла списку
struct Node {
    int data;
    struct Node* next;
};

// Функція для створення нового вузла
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Функція для додавання нового вузла в кінець списку
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функція для пошуку елементу в списку
struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Функція для виведення всього списку
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    printf("Список: ");
    printList(head);

    int key = 20;
    struct Node* result = search(head, key);
    if (result != NULL) {
        printf("%d знайдено в списку.\n", key);
    } else {
        printf("%d не знайдено в списку.\n", key);
    }

    key = 40;
    result = search(head, key);
    if (result != NULL) {
        printf("%d знайдено в списку.\n", key);
    } else {
        printf("%d не знайдено в списку.\n", key);
    }

    return 0;
}
