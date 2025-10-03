#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

Node* search(Node* root, int key) {
    if (root == nullptr || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int main() {
    Node* root = nullptr;
    int keys[] = {50, 30, 20, 40, 70, 60, 80};

    for (int key : keys) {
        root = insert(root, key);
    }

    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    int searchKey = 60;
    Node* result = search(root, searchKey);

    if (result != nullptr) {
        std::cout << "Key " << searchKey << " found in the tree." << std::endl;
    } else {
        std::cout << "Key " << searchKey << " not found in the tree." << std::endl;
    }

    return 0;
}
