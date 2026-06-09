#include <iostream>
#include <cmath>
using namespace std;
// Nodo Patricia
class PatriciaTrieNode {
public:
    int number;
    int data;

    PatriciaTrieNode* leftChild;
    PatriciaTrieNode* rightChild;

    PatriciaTrieNode() {
        number = 0;
        data = 0;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};
class PatriciaTrie {
private:
    PatriciaTrieNode* root;

    static const int MaxBits = 10;

    // Obtiene el bit i-ésimo del número k
    bool bit(int k, int i) {
        string binary = "";

        int temp = k;

        while (temp > 0) {
            binary = char((temp % 2) + '0') + binary;
            temp /= 2;
        }

        while (binary.length() < MaxBits)
            binary = "0" + binary;

        return binary[i - 1] == '1';
    }

    PatriciaTrieNode* search(PatriciaTrieNode* t,
                             int k) {

        if (t == nullptr)
            return nullptr;

        PatriciaTrieNode* currentNode = t;
        PatriciaTrieNode* nextNode = t->leftChild;

        while (nextNode->number >
               currentNode->number) {

            currentNode = nextNode;

            nextNode =
                bit(k, nextNode->number)
                ? nextNode->rightChild
                : nextNode->leftChild;
        }

        return nextNode;
    }

    PatriciaTrieNode* insert(PatriciaTrieNode* t,
                             int element) {

        PatriciaTrieNode* current = nullptr;
        PatriciaTrieNode* parent;
        PatriciaTrieNode* lastNode;
        PatriciaTrieNode* newNode;

        int i;

        if (t == nullptr) {
            t = new PatriciaTrieNode();

            t->number = 0;
            t->data = element;

            t->leftChild = t;
            t->rightChild = nullptr;

            return t;
        }

        lastNode = search(t, element);

        if (element == lastNode->data) {
            cout << "Key already Present"
                 << endl;
            return t;
        }

        for (i = 1;
             bit(element, i) ==
             bit(lastNode->data, i);
             i++) {
            current = t->leftChild;
        }

        parent = t;
        current = t->leftChild;

        while (current->number >
                   parent->number &&
               current->number < i) {

            parent = current;

            current =
                bit(element,
                    current->number)
                ? current->rightChild
                : current->leftChild;
        }

        newNode = new PatriciaTrieNode();

        newNode->number = i;
        newNode->data = element;

        newNode->leftChild =
            bit(element, i)
            ? current
            : newNode;

        newNode->rightChild =
            bit(element, i)
            ? newNode
            : current;

        if (current == parent->leftChild) {
            parent->leftChild =
                newNode;
        }
        else {
            parent->rightChild =
                newNode;
        }
        return t;
    }
public:
    PatriciaTrie() { root = nullptr; }

    bool isEmpty() { return root == nullptr; }

    void makeEmpty() { root = nullptr; }

    bool search(int k) {
        int num =
            (int)(log(k) / log(2));

        if (num > MaxBits) {
            cout << "Exceeded the limit"
                 << endl;
            return false;
        }

        PatriciaTrieNode* node = search(root, k);

        if (node == nullptr)
            return false;
        return node->data == k;
    }

    void insert(int element) {
        int num =
            (int)(log(element)
            / log(2)) + 1;

        if (num > MaxBits) {
            cout
            << "We are full, The number is too large"
            << endl;
            return;
        }
        root =
            insert(root, element);
    }
};

int main() {
    PatriciaTrie pt;
    char ch;

    cout << "Patricia Trie\n";
    do {
        cout << "\nPatricia Trie Operations\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Check Empty\n";
        cout << "4. Make Empty\n";

        cout << "Make your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;

            cout
            << "Enter element to insert: ";
            cin >> value;
            pt.insert(value);

            break;
        }
        case 2: {
            int value;

            cout
            << "Enter element to search: ";
            cin >> value;
            cout
            << "Search result: "
            << (pt.search(value)
                ? "true"
                : "false")
            << endl;

            break;
        }
        case 3:
            cout
            << "Empty status: "
            << (pt.isEmpty()
                ? "true"
                : "false")
            << endl;
            break;
        case 4:
            pt.makeEmpty();

            cout << "Patricia Trie Cleared" << endl;
            break;

        default:
            cout << "Wrong entry" << endl;
        }

        cout << "\nDo you want to continue (y/n)? ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}