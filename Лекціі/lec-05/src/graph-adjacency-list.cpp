#include <iostream>
#include <new>

struct Node {
    int vertex;
    Node* next;
};

bool addEdge(Node** head, int n, int u, int v) {
    if (!head || u < 0 || v < 0 || u >= n || v >= n || u == v)
        return false;
    for (Node* p = head[u]; p; p = p->next)
        if (p->vertex == v) return false;
    Node* a = new (std::nothrow) Node{v, head[u]};
    if (!a) return false;
    Node* b = new (std::nothrow) Node{u, head[v]};
    if (!b) { delete a; return false; }
    head[u] = a;
    head[v] = b;
    return true;
}

void clear(Node**& head, int n) {
    if (!head) return;
    for (int u = 0; u < n; ++u) {
        while (head[u]) {
            Node* old = head[u];
            head[u] = old->next;
            delete old;
        }
    }
    delete[] head;
    head = nullptr;
}

int main() {
    const int n = 5;
    Node** head = new (std::nothrow) Node*[n]{};
    if (!head) return 1;
    if (!addEdge(head, n, 0, 1) || !addEdge(head, n, 0, 2) ||
        !addEdge(head, n, 1, 2) || !addEdge(head, n, 2, 3)) {
        clear(head, n);
        std::cerr << "Cannot add edge\n";
        return 1;
    }
    for (int u = 0; u < n; ++u) {
        std::cout << u << ':';
        for (const Node* p = head[u]; p; p = p->next)
            std::cout << ' ' << p->vertex;
        std::cout << '\n';
    }
    clear(head, n);
    clear(head, n);
}
