#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
// Nodo Trie
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    TrieNode() { isEnd = false; }
};

// Trie
class Trie {
private:
    TrieNode* root;
public:

    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* current = root;

        for(char ch : word) {
            if(current->children.find(ch)
                == current->children.end()) {

                current->children[ch] =
                    new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEnd = true;
    }

    bool search(string word) {
        TrieNode* current = root;

        for(char ch : word) {
            if(current->children.find(ch)
                == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEnd;
    }
};
int main() {
    Trie trie;

    trie.insert("hello");
    trie.insert("help");
    trie.insert("hero");
    trie.insert("world");

    cout << "Buscar hello: "
         << (trie.search("hello")
         ? "Si" : "No") << endl;

    cout << "Buscar help: "
         << (trie.search("help")
         ? "Si" : "No") << endl;

    cout << "Buscar house: "
         << (trie.search("house")
         ? "Si" : "No") << endl;

    return 0;
}