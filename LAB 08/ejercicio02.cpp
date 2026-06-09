#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    // Constructor
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
    // Verifica si un nodo no tiene hijos
    bool isEmpty(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr)
                return false;
        }
        return true;
    }
    // Función recursiva de borrado
    TrieNode* remove(TrieNode* node, const string& key, int depth) {
        if (node == nullptr)
            return nullptr;
        // Se llegó al final de la palabra
        if (depth == key.length()) {
            // Desmarcar fin de palabra
            if (node->isEndOfWord)
                node->isEndOfWord = false;
            // Si no tiene hijos, eliminar nodo
            if (isEmpty(node)) {
                delete node;
                node = nullptr;
            }

            return node;
        }

        int index = key[depth] - 'a';
        node->children[index] =
            remove(node->children[index],
                   key,
                   depth + 1);
        // Si el nodo quedó sin hijos y no es fin de palabra
        if (isEmpty(node) && !node->isEndOfWord) {
            delete node;
            node = nullptr;
        }
        return node;
    }
public:
    // Constructor
    Trie() {
        root = new TrieNode();
    }
    // Insertar palabra
    void insert(const string& key) {
        TrieNode* current = root;
        for (char ch : key) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
    // Buscar palabra
    bool search(const string& key) {
        TrieNode* current = root;
        for (char ch : key) {
            int index = ch - 'a';
            if (current->children[index] == nullptr)
                return false;
            current = current->children[index];
        }
        return current != nullptr &&
               current->isEndOfWord;
    }
    // Método público para eliminar
    void remove(const string& key) {
        root = remove(root, key, 0);
        // Evitar que la raíz quede nula
        if (root == nullptr)
            root = new TrieNode();
    }
};

int main() {
    string keys[] = {
        "the", "a", "there",
        "answer", "any", "by",
        "bye", "their",
        "hero", "heroplane"
    };
    int n = sizeof(keys) / sizeof(keys[0]);
    Trie trie;
    // Construcción del Trie
    for (int i = 0; i < n; i++) {
        trie.insert(keys[i]);
    }
    // Búsquedas
    cout << "Buscar 'the': ";
    cout << (trie.search("the") ? "Si" : "No") << endl;
    cout << "Buscar 'these': ";
    cout << (trie.search("these") ? "Si" : "No") << endl;
    // Eliminar palabra
    trie.remove("heroplane");
    cout << "Buscar 'hero' despues de eliminar 'heroplane': ";
    cout << (trie.search("hero") ? "Si" : "No") << endl;
    return 0;
}
