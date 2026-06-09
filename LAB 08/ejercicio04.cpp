#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
// Nodo Trie
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    char c;
    bool isWord;
    TrieNode(char character) {
        c = character;
        isWord = false;
    }
    TrieNode() {
        c = '\0';
        isWord = false;
    }
    // Inserción recursiva
    void insert(const string& word, int index = 0) {
        if (index >= word.length())
            return;

        char currentChar = word[index];
        TrieNode* child;

        if (children.find(currentChar) == children.end()) {
            child = new TrieNode(currentChar);
            children[currentChar] = child;
        }
        else {
            child = children[currentChar];
        }

        if (index < word.length() - 1)
            child->insert(word, index + 1);
        else
            child->isWord = true;
    }
};
// Clase Trie
class Trie {
private:
    TrieNode* root;
    // Función auxiliar recursiva para sugerencias
    void suggestHelper(TrieNode* node,
                       vector<string>& suggestions,
                       string currentWord) {

        if (node->isWord) {
            suggestions.push_back(currentWord);
        }
        for (auto& pair : node->children) {


            char nextChar = pair.first;
            TrieNode* child = pair.second;


            suggestHelper(child,
                          suggestions,
                          currentWord + nextChar);
        }
    }
public:
    // Constructor
    Trie(const vector<string>& words) {
        root = new TrieNode();
        for (const string& word : words) {
            root->insert(word);
        }
    }
    // Buscar prefijo o palabra exacta
    bool find(const string& prefix, bool exact = false) {
        TrieNode* current = root;

        for (char c : prefix) {
            if (current->children.find(c) ==
                current->children.end()) {
                return false;
            }

            current = current->children[c];
        }
        return !exact || current->isWord;
    }
    // Obtener sugerencias
    vector<string> suggest(const string& prefix) {
        vector<string> suggestions;
        TrieNode* current = root;
        string currentWord = "";

        for (char c : prefix) {
            if (current->children.find(c) ==
                current->children.end()) {
                return suggestions;
            }

            current = current->children[c];
            currentWord += c;
        }
        suggestHelper(current,
                      suggestions,
                      currentWord);
        return suggestions;
    }
};
// Programa principal
int main() {
    vector<string> words = {
        "hello",
        "dog",
        "hell",
        "cat",
        "a",
        "hel",
        "help",
        "helps",
        "helping"
    };
    Trie trie(words);
    vector<string> result =
        trie.suggest("hel");

    cout << "Sugerencias para 'hel':\n";

    for (const string& word : result) {
        cout << word << endl;
    }
    return 0;
}