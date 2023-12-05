#include <stdio.h>
#include <stdlib.h>

// Структура для представлення вузла бінарного дерева
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Функція для створення нового вузла з заданим ключем
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Функція для вставки ключа в бінарне дерево пошуку
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Функція для обходу бінарного дерева у порядку
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Функція для пошуку ключа в бінарному дереві
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int keys[] = {50, 30, 20, 40, 70, 60, 80};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        root = insert(root, keys[i]);
    }

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    int searchKey = 60;
    struct Node* result = search(root, searchKey);

    if (result != NULL) {
        printf("Key %d found in the tree.\n", searchKey);
    } else {
        printf("Key %d not found in the tree.\n", searchKey);
    }

    return 0;
}
