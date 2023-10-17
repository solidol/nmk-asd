#include <stdio.h>
#include <stdlib.h>

// Структура для вузла бінарного дерева
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Функція для створення нового вузла
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Функція для вставки вузла в BST
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Функція для пошуку вузла в BST
struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Функція для видалення вузла з BST
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Функція для виведення BST в порядку "inorder"
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    int key = 30;
    if (search(root, key) != NULL) {
        printf("%d found in the tree.\n", key);
    } else {
        printf("%d not found in the tree.\n", key);
    }

    key = 60;
    if (search(root, key) != NULL) {
        printf("%d found in the tree.\n", key);
    } else {
        printf("%d not found in the tree.\n", key);
    }

    root = deleteNode(root, 30);
    printf("Inorder Traversal after deleting 30: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
