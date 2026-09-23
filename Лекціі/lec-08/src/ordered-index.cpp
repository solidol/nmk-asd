#include <iostream>
#include <new>

struct Record {
    int code;
    const char* name;
};

struct IndexEntry {
    int key;
    const Record* record; // Не володіє записом.
};

// Передумова: n >= 0; для n > 0 обидва масиви мають n елементів.
void buildIndex(const Record* records, IndexEntry* index, int n) {
    for (int i = 0; i < n; ++i)
        index[i] = IndexEntry{records[i].code, &records[i]};
    for (int i = 1; i < n; ++i) {
        IndexEntry current = index[i];
        int j = i;
        while (j > 0 && index[j - 1].key > current.key) {
            index[j] = index[j - 1];
            --j;
        }
        index[j] = current;
    }
}

// Для порожнього індексу дозволено index == nullptr, n == 0.
int lowerBound(const IndexEntry* index, int n, int key) {
    int left = 0;
    int right = n;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (index[middle].key < key)
            left = middle + 1;
        else
            right = middle;
    }
    return left;
}

void printMatches(const IndexEntry* index, int n, int key) {
    int i = lowerBound(index, n, key);
    if (i == n || index[i].key != key) {
        std::cout << "Not found\n";
        return;
    }
    while (i < n && index[i].key == key) {
        const Record* record = index[i].record;
        std::cout << record->code << ' ' << record->name << '\n';
        ++i;
    }
}

int main() {
    int key;
    std::cout << "Enter product code: ";
    if (!(std::cin >> key)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    const int n = 4;
    Record* records = new (std::nothrow) Record[n]{
        {30, "ruler"}, {10, "pen"}, {20, "pencil"}, {20, "notebook"}
    };
    if (!records) {
        std::cerr << "Allocation failed\n";
        return 1;
    }
    IndexEntry* index = new (std::nothrow) IndexEntry[n];
    if (!index) {
        delete[] records;
        std::cerr << "Allocation failed\n";
        return 1;
    }
    buildIndex(records, index, n);
    printMatches(index, n, key);
    delete[] index;
    delete[] records;
    return 0;
}
