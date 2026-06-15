#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Hash {
private:
    int bucket;                     // Número de cubos
    vector<vector<int>> table;      // Tabla hash

public:
    // Constructor
    Hash(int bucket) {
        this->bucket = bucket;
        table.resize(bucket);
    }
    // Función hash
    int hashFunction(int key) {
        return key % bucket;
    }
    // Insertar elemento
    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }
    // Eliminar elemento
    void deleteItem(int key) {
        int index = hashFunction(key);

        auto it = find(table[index].begin(),
                       table[index].end(),
                       key);

        if (it != table[index].end()) {
            table[index].erase(it);
        }
    }
    // Mostrar tabla hash
    void displayHash() {
        for (int i = 0; i < bucket; i++) {
            cout << i;
            for (int x : table[i]) {
                cout << " --> " << x;
            }
            cout << endl;
        }
    }
};

int main() {
    // Arreglo de claves
    int a[] = {15, 11, 27, 8, 12};
    // Crear tabla hash con 7 cubos
    Hash h(7);
    // Insertar claves
    for (int x : a) { h.insertItem(x); }
    // Eliminar 12
    h.deleteItem(12);
    // Mostrar tabla hash
    h.displayHash();

    return 0;
}
