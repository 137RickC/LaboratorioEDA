#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 26;
class HashTable {
private:
    struct Entry {
        string key;
        int count;
        Entry* next;
        Entry(string k) : key(k), count(1), next(nullptr) {}
    };
    Entry* table[TABLE_SIZE];
    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key)
            hash = (hash * 31 + c) % TABLE_SIZE;
        return hash;
    }
public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr;
    }
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Entry* curr = table[i];
            while (curr) {
                Entry* next = curr->next;
                delete curr;
                curr = next;
            }
        }
    }
    void insert(const string& key) {
        int idx = hashFunction(key);
        Entry* curr = table[idx];
        while (curr) {
            if (curr->key == key) { curr->count++; return; }
            curr = curr->next;
        }
        Entry* e = new Entry(key);
        e->next = table[idx];
        table[idx] = e;
    }
    int search(const string& key) {
        int idx = hashFunction(key);
        Entry* curr = table[idx];
        while (curr) {
            if (curr->key == key) return curr->count;
            curr = curr->next;
        }
        return 0;
    }
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i]) {
                cout << "[" << i << "] ";
                Entry* curr = table[i];
                while (curr) {
                    cout << curr->key << ":" << curr->count;
                    if (curr->next) cout << " -> ";
                    curr = curr->next;
                }
                cout << endl;
            }
        }
    }
};

int main() {
    HashTable ht;
    string palabras[] = {"casa", "auto", "mesa", "casa", "libro",
                         "auto", "casa", "mesa", "auto", "libro"};
    for (int i = 0; i < 10; i++)
        ht.insert(palabras[i]);

    cout << "Frecuencia de palabras:" << endl;
    ht.display();

    cout << "\nBuscar 'casa':  " << ht.search("casa")  << " veces" << endl;
    cout << "Buscar 'libro': " << ht.search("libro") << " veces" << endl;
    cout << "Buscar 'perro': " << ht.search("perro") << " veces" << endl;

    return 0;
}
