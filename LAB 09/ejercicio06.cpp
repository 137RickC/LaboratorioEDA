#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Hash {
private:
    int bucketCount;      // Número de depósitos
    int numOfElements;    // Número de elementos almacenados

    vector<vector<int>> table;


    // Función hash
    int getHashIndex(int key) { return key % bucketCount; }

    // Calcular factor de carga
    float getLoadFactor() {
        return (float)numOfElements / bucketCount;
    }
    // Rehashing
    void rehash() {
        // Guardar la tabla anterior
        vector<vector<int>> oldTable = table;
        // Duplicar capacidad
        bucketCount *= 2;
        // Crear nueva tabla vacía
        table.clear();
        table.resize(bucketCount);
        // Reiniciar contador
        numOfElements = 0;
        // Reinsertar todos los elementos
        for (auto &bucket : oldTable) {
            for (int key : bucket) {
                insert(key);
            }
        }
    }
public:
    // Constructor
    Hash(int buckets) {
        bucketCount = buckets;
        numOfElements = 0;
        table.resize(bucketCount);
    }
    // Insertar clave
    void insert(int key) {
        // Si el factor de carga supera 0.5
        while (getLoadFactor() > 0.5) {
            rehash();
        }

        int index = getHashIndex(key);
        table[index].push_back(key);

        numOfElements++;
    }
    // Eliminar clave
    void remove(int key) {
        int index = getHashIndex(key);

        auto it = find(
            table[index].begin(),
            table[index].end(),
            key
        );

        if (it != table[index].end()) {
            table[index].erase(it);
            numOfElements--;
        }
    }
    // Mostrar tabla
    void display() {
        for (int i = 0; i < bucketCount; i++) {
            cout << i;

            for (int key : table[i]) {
                cout << " --> " << key;
            }
            cout << endl;
        }
    }
};
int main() {
    int keys[] = {15, 11, 27};
    int n = sizeof(keys) / sizeof(keys[0]);

    Hash hashTable(5);

    // Insertar elementos
    for (int i = 0; i < n; i++) {
        hashTable.insert(keys[i]);
    }

    // Eliminar una clave
    hashTable.remove(11);

    hashTable.display();

    // Insertar nuevo elemento
    hashTable.insert(19);

    cout << "\nDespues del rehashing:\n";
    hashTable.display();

    return 0;
}
