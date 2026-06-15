#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Nodo Trie
class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

// Clase Trie
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;

        for(char ch : word) {
            int index = ch - 'a';

            if(current->children[index] == nullptr)
                current->children[index] = new TrieNode();

            current = current->children[index];
        }

        current->isEnd = true;
    }

    bool search(string word) {
        TrieNode* current = root;

        for(char ch : word) {
            int index = ch - 'a';

            if(current->children[index] == nullptr)
                return false;

            current = current->children[index];
        }

        return current->isEnd;
    }
};

// Función recursiva para segmentar
bool wordBreak(string str,
               Trie& trie,
               vector<string>& result) {

    if(str.empty())
        return true;

    for(int i = 1; i <= str.length(); i++) {

        string prefix = str.substr(0, i);

        if(trie.search(prefix)) {

            result.push_back(prefix);

            if(wordBreak(str.substr(i), trie, result))
                return true;

            result.pop_back();
        }
    }

    return false;
}

int main() {

    Trie trie;

    vector<string> dictionary = {
        "i", "like", "sam", "sung",
        "samsung", "mobile", "ice",
        "cream", "icecream", "man",
        "go", "mango"
    };

    for(string word : dictionary)
        trie.insert(word);

    string text = "ilikesamsung";

    vector<string> result;

    if(wordBreak(text, trie, result)) {

        cout << "Segmentacion encontrada:\n";

        for(string word : result)
            cout << word << " ";

        cout << endl;
    }
    else {
        cout << "No existe segmentacion valida\n";
    }

    return 0;
}