#include <iostream>
#include <new>

struct Node {
    char value;
    Node* left;
    Node* right;
};

void preorder(const Node* p) {
    if (!p) return;
    std::cout << p->value << ' ';
    preorder(p->left);
    preorder(p->right);
}

void inorder(const Node* p) {
    if (!p) return;
    inorder(p->left);
    std::cout << p->value << ' ';
    inorder(p->right);
}

void postorder(const Node* p) {
    if (!p) return;
    postorder(p->left);
    postorder(p->right);
    std::cout << p->value << ' ';
}

void clear(Node*& p) {
    if (!p) return;
    clear(p->left);
    clear(p->right);
    delete p;
    p = nullptr;
}

int main() {
    Node* root = nullptr;
    try {
        root = new Node{'A', nullptr, nullptr};
        root->left = new Node{'B', nullptr, nullptr};
        root->right = new Node{'C', nullptr, nullptr};
        root->left->left = new Node{'D', nullptr, nullptr};
        root->left->right = new Node{'E', nullptr, nullptr};
        root->right->right = new Node{'F', nullptr, nullptr};
    } catch (const std::bad_alloc&) {
        clear(root);
        std::cerr << "Allocation failed\n";
        return 1;
    }
    preorder(root); std::cout << '\n';
    inorder(root); std::cout << '\n';
    postorder(root); std::cout << '\n';
    clear(root);
    clear(root); // Повторне очищення порожнього дерева безпечне.
}
