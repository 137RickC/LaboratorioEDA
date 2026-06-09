#include <iostream>
#include <string>
using namespace std;
// Nodo Trie
class TrieNode {
public:
    TrieNode* children[26];
    bool isLeaf;
    // Constructor
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isLeaf = false;
    }
};
// Clase Trie
class Trie {
private:
    TrieNode* root;
    // Verifica si un nodo es hoja
    bool isLeafNode(TrieNode* node) {
        return node->isLeaf;
    }
    // Función recursiva para mostrar el contenido
    void display(TrieNode* node, string currentWord) {
        // Si se llegó al final de una palabra
        if (isLeafNode(node)) { cout << currentWord << endl; }
        // Recorrer todos los hijos
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                char character = 'a' + i;
                display(node->children[i],
                        currentWord + character);
            }
        }
    }
public:
    // Constructor
    Trie() { root = new TrieNode(); }
    // Insertar palabra
    void insert(const string& key) {
        TrieNode* current = root;
        for (char ch : key) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] =
                    new TrieNode();
            }
            current = current->children[index];
        }
        current->isLeaf = true;
    }
    // Mostrar todo el contenido del Trie
    void display() {
        cout << "Contenido del Trie:" << endl;
        string word = "";
        display(root, word);
    }
};
// Programa principal
int main() {
    string keys[] = {
        "the",
        "a",
        "there",
        "answer",
        "any",
        "by",
        "bye",
        "their"
    };
    int n = sizeof(keys) / sizeof(keys[0]);
    Trie trie;
    // Insertar claves
    for (int i = 0; i < n; i++) {
        trie.insert(keys[i]);
    }
    // Mostrar contenido
    trie.display();
    return 0;
}
