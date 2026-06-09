#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Nodo del Trie de Sufijos
class SuffixTrieNode {
private:
    static const int MAX_CHAR = 256;
public:
    SuffixTrieNode* children[MAX_CHAR];
    vector<int> indexes;
    // Constructor
    SuffixTrieNode() {
        for (int i = 0; i < MAX_CHAR; i++) {
            children[i] = nullptr;
        }
    }

    // Inserta un sufijo en el Trie
    void insertSuffix(const string& s, int index) {
        indexes.push_back(index);

        if (!s.empty()) {
            unsigned char c = s[0];

            if (children[c] == nullptr) {
                children[c] = new SuffixTrieNode();
            }

            children[c]->insertSuffix(
                s.substr(1),
                index + 1
            );
        }
    }
    // Busca un patrón
    vector<int>* search(const string& s) {
        if (s.empty()) { return &indexes; }

        unsigned char c = s[0];

        if (children[c] != nullptr) {
            return children[c]->search(
                s.substr(1)
            );
        }
        return nullptr;
    }
};
// Trie de Sufijos
class SuffixTrie {
private:
    SuffixTrieNode* root;
public:
    // Constructor
    SuffixTrie(const string& text) {
        root = new SuffixTrieNode();
        // Insertar todos los sufijos
        for (int i = 0; i < text.length(); i++) {
            root->insertSuffix(
                text.substr(i),
                i
            );
        }
    }
    // Buscar patrón
    void searchPattern(const string& pattern) {
        vector<int>* result =
            root->search(pattern);

        if (result == nullptr) {
            cout << "Patron no encontrado"
                 << endl;
            return;
        }
        int patternLength = pattern.length();

        for (int pos : *result) {
            cout << "Patron encontrado en la posicion "
                 << (pos - patternLength)
                 << endl;
        }
    }
};
// Programa principal
int main() {
    string text = "geeksforgeeks.org";
    SuffixTrie trie(text);

    cout << "Buscar por 'ee'\n";
    trie.searchPattern("ee");

    cout << "\nBuscar por 'geek'\n";
    trie.searchPattern("geek");

    cout << "\nBuscar por 'quiz'\n";
    trie.searchPattern("quiz");

    cout << "\nBuscar por 'forgeeks'\n";
    trie.searchPattern("forgeeks");

    return 0;
}
