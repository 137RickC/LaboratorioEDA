#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

class Trie {
private:
    TrieNode* root;

    void displaySorted(TrieNode* node,
                       string currentWord) {

        if(node->isEnd)
            cout << currentWord << endl;

        for(int i = 0; i < 26; i++) {
            if(node->children[i] != nullptr) {
                char ch = 'a' + i;
                displaySorted(
                    node->children[i],
                    currentWord + ch
                );
            }
        }
    }

public:
    Trie() { root = new TrieNode(); }

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

    void sortWords() {
        cout << "Palabras ordenadas:\n";
        displaySorted(root, "");
    }
};

int main() {

    vector<string> words = {
        "banana",
        "apple",
        "orange",
        "grape",
        "pear",
        "kiwi"
    };

    Trie trie;

    for(string word : words)
        trie.insert(word);

    trie.sortWords();

    return 0;
}