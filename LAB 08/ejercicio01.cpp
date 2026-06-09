#include <iostream>
#include <string>
using namespace std;
// Clase auxiliar TrieNode
class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    // Constructor
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};
// Clase Trie
class Trie {
private:
    TrieNode* root;

public:
    // Constructor
    Trie() {
        root = new TrieNode();
    }
    // Insertar una palabra en el Trie
    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
    // Buscar una palabra en el Trie
    bool search(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return false; // Palabra no encontrada
            }
            current = current->children[index];
        }
        return current != nullptr && current->isEndOfWord;
    }
    // Verificar si existe un prefijo
    bool startsWith(const string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return false; // Prefijo no encontrado
            }
            current = current->children[index];
        }
        return true;
    }
};
// Método principal
int main() {
    Trie trie;
    // Inserción de palabras
    trie.insert("hello");
    trie.insert("world");

    cout << "Busqueda de 'hello': "
         << (trie.search("hello") ? "true" : "false") << endl;
    cout << "Busqueda de 'world': "
         << (trie.search("world") ? "true" : "false") << endl;
    cout << "Busqueda de 'hi': "
         << (trie.search("hi") ? "true" : "false") << endl;
    cout << "Prefijo 'hell': "
         << (trie.startsWith("hell") ? "true" : "false") << endl;
    return 0;
}
