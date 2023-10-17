#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int val) {
        root = insertRecursive(root, val);
    }

    bool search(int val) {
        return searchRecursive(root, val);
    }

private:
    Node* root;

    Node* insertRecursive(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insertRecursive(node->left, val);
        } else if (val > node->data) {
            node->right = insertRecursive(node->right, val);
        }

        return node;
    }

    bool searchRecursive(Node* node, int val) {
        if (node == nullptr) {
            return false;
        }

        if (val == node->data) {
            return true;
        } else if (val < node->data) {
            return searchRecursive(node->left, val);
        } else {
            return searchRecursive(node->right, val);
        }
    }
};

int main() {
    BinarySearchTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(1);
    tree.insert(4);

    int key = 4;
    if (tree.search(key)) {
        std::cout << key << " found in the tree." << std::endl;
    } else {
        std::cout << key << " not found in the tree." << std::endl;
    }

    key = 6;
    if (tree.search(key)) {
        std::cout << key << " found in the tree." << std::endl;
    } else {
        std::cout << key << " not found in the tree." << std::endl;
    }

    return 0;
}
