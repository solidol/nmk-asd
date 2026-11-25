#include <iostream>
#include <sstream>
#include <string>

class BinarySearchTree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* insertNode(Node* node, int key) {
        if (node == nullptr) {
            return new Node{key, nullptr, nullptr};
        }

        if (key < node->key) {
            node->left = insertNode(node->left, key);
        } else if (key > node->key) {
            node->right = insertNode(node->right, key);
        }
        return node;
    }

    void clear(Node* node) {
        if (node == nullptr) {
            return;
        }

        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        clear(root);
    }

    BinarySearchTree(const BinarySearchTree&) = delete;
    BinarySearchTree& operator=(const BinarySearchTree&) = delete;

    void insert(int key) {
        root = insertNode(root, key);
    }

    bool contains(int key) const {
        const Node* current = root;
        while (current != nullptr) {
            if (key == current->key) {
                return true;
            }
            if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }
};

int main() {
    BinarySearchTree tree;
    const int keys[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int key : keys) {
        tree.insert(key);
    }

    std::cout << "Enter one integer to find: ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    int key;
    char extra;
    if (!(input >> key) || (input >> extra)) {
        std::cerr << "Expected one integer.\n";
        return 1;
    }

    if (tree.contains(key)) {
        std::cout << "Found.\n";
    } else {
        std::cout << "Not found.\n";
    }
    return 0;
}
