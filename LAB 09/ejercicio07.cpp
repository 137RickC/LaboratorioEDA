#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

// Clase que almacena pares clave-valor
class ValueEntry {
public:
    string key;
    int value;

    ValueEntry(string k, int v) {
        key = k;
        value = v;
    }
};
// Tabla Hash con Doble Hashing
class HashTable {
private:
    int HASH_TABLE_SIZE;
    int size;
    int totalPrimeSize;

    vector<ValueEntry*> table;
    // Buscar el mayor primo menor que el tamaño de la tabla
    int getPrime() {
        for (int i = HASH_TABLE_SIZE - 1; i >= 2; i--) {
            bool prime = true;

            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    prime = false;
                    break;
                }
            }

            if (prime)
                return i;
        }
        return 3;
    }
    // Primera función hash
    int myhash1(string key) {
        hash<string> hashFunc;

        int hashValue =
            static_cast<int>(hashFunc(key) % HASH_TABLE_SIZE);

        if (hashValue < 0)
            hashValue += HASH_TABLE_SIZE;

        return hashValue;
    }
    // Segunda función hash
    int myhash2(string key) {
        hash<string> hashFunc;

        int hashValue =
            static_cast<int>(hashFunc(key) % HASH_TABLE_SIZE);

        if (hashValue < 0)
            hashValue += HASH_TABLE_SIZE;

        return totalPrimeSize -
               (hashValue % totalPrimeSize);
    }
public:
    // Constructor
    HashTable(int ts) {
        size = 0;
        HASH_TABLE_SIZE = ts;
        table.resize(HASH_TABLE_SIZE, nullptr);

        totalPrimeSize = getPrime();
    }
    // Obtener cantidad de elementos
    int getSize() { return size; }
    // Verificar si está vacía
    bool isEmpty() { return size == 0; }
    // Vaciar tabla
    void makeEmpty() {
        for (int i = 0; i < HASH_TABLE_SIZE; i++) {
            if (table[i] != nullptr) {
                delete table[i];
                table[i] = nullptr;
            }
        }

        size = 0;
    }
    // Buscar valor asociado a una clave
    int getKey(string key) {
        int hash1 = myhash1(key);
        int hash2 = myhash2(key);

        while (table[hash1] != nullptr &&
               table[hash1]->key != key) {

            hash1 += hash2;
            hash1 %= HASH_TABLE_SIZE;
        }
        if (table[hash1] == nullptr)
            return -1;

        return table[hash1]->value;
    }
    // Insertar
    void insert(string key, int value) {
        if (size == HASH_TABLE_SIZE) {
            cout << "La tabla está llena"
                 << endl;

            return;
        }

        int hash1 = myhash1(key);
        int hash2 = myhash2(key);

        while (table[hash1] != nullptr) {
            hash1 += hash2;
            hash1 %= HASH_TABLE_SIZE;
        }

        table[hash1] = new ValueEntry(key, value);

        size++;
    }
    // Eliminar
    void remove(string key) {
        int hash1 = myhash1(key);
        int hash2 = myhash2(key);

        while (table[hash1] != nullptr &&
               table[hash1]->key != key) {

            hash1 += hash2;
            hash1 %= HASH_TABLE_SIZE;
        }

        if (table[hash1] != nullptr) {
            delete table[hash1];
            table[hash1] = nullptr;

            size--;
        }
    }
    // Mostrar tabla
    void printHashTable() {
        cout << "\nHash Table\n";

        for (int i = 0; i < HASH_TABLE_SIZE; i++) {
            if (table[i] != nullptr) {
                cout << table[i]->key
                     << " "
                     << table[i]->value
                     << endl;
            }
        }
    }
    // Destructor
    ~HashTable() {
        for (int i = 0; i < HASH_TABLE_SIZE; i++) {
            if (table[i] != nullptr)
                delete table[i];
        }
    }
};

int main() {
    cout << "Prueba de Tabla Hash\n";
    HashTable ht(100);

    ht.insert("primo", 97);
    ht.insert("par", 96);
    ht.insert("impar", 95);

    ht.printHashTable();

    return 0;
}
