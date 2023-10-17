#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    bool search(int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }

private:
    Node* head;
};

int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);

    std::cout << "Список: ";
    list.printList();

    int key = 20;
    if (list.search(key)) {
        std::cout << key << " знайдено в списку." << std::endl;
    } else {
        std::cout << key << " не знайдено в списку." << std::endl;
    }

    key = 40;
    if (list.search(key)) {
        std::cout << key << " знайдено в списку." << std::endl;
    } else {
        std::cout << key << " не знайдено в списку." << std::endl;
    }

    return 0;
}
