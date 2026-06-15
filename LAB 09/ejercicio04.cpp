#include <iostream>
#include <vector>


using namespace std;


class DoubleHash {
private:
    int TABLE_SIZE;
    int keysPresent;
    int PRIME;

    vector<int> hashTable;
    vector<bool> isPrime;
    static const long MAX_SIZE = 10000001;
    
    // Criba de Eratóstenes
    void setSieve() {
        isPrime[0] = true;
        isPrime[1] = true;

        for (long i = 2; i * i <= MAX_SIZE; i++) {
            if (!isPrime[i]) {
                for (long j = i * i; j <= MAX_SIZE; j += i) {
                    isPrime[j] = true;
                }
            }
        }
    }
    // Primera función hash
    int hash1(int value) { return value % TABLE_SIZE; }
    // Segunda función hash
    int hash2(int value) { return PRIME - (value % PRIME); }
    bool isFull() { return keysPresent == TABLE_SIZE; }
public:
    // Constructor
    DoubleHash(int n) {

        isPrime.resize(MAX_SIZE + 1, false);

        setSieve();
        TABLE_SIZE = n;
        // Encontrar el mayor primo menor que TABLE_SIZE
        PRIME = TABLE_SIZE - 1;
        while (isPrime[PRIME]) { PRIME--; }
        keysPresent = 0;
        // Inicializar tabla con -1
        hashTable.resize(TABLE_SIZE, -1);
    }

    // Mostrar números primos (opcional)
    void printPrime(long n) {
        for (long i = 0; i <= n; i++) {
            if (!isPrime[i]) {
                cout << i << ", ";
            }
        }
        cout << endl;
    }

    // Insertar elemento
    void insert(int value) {
        if (value == -1 || value == -2) {
            cout << "ERROR : -1 y -2 no pueden insertarse" << endl;
            return;
        }

        if (isFull()) {
            cout << "ERROR : Tabla Hash Llena" << endl;
            return;
        }

        int probe = hash1(value);
        int offset = hash2(value);

        while (hashTable[probe] != -1) {
            if (hashTable[probe] == -2)
                break;

            probe = (probe + offset) % TABLE_SIZE;
        }
        hashTable[probe] = value;
        keysPresent++;
    }
    // Buscar elemento
    bool search(int value) {
        int probe = hash1(value);
        int offset = hash2(value);

        int initialPos = probe;
        bool firstItr = true;

        while (true) {

            if (hashTable[probe] == -1)
                break;

            else if (hashTable[probe] == value)
                return true;

            else if (probe == initialPos && !firstItr)
                return false;

            else
                probe = (probe + offset) % TABLE_SIZE;

            firstItr = false;
        }

        return false;
    }
    // Eliminar elemento
    void erase(int value) {
        if (!search(value)) return;

        int probe = hash1(value);
        int offset = hash2(value);

        while (hashTable[probe] != -1) {
            if (hashTable[probe] == value) {
                hashTable[probe] = -2; // marca como eliminado

                keysPresent--;

                return;
            }

            probe = (probe + offset) % TABLE_SIZE;
        }
    }

    // Mostrar tabla hash
    void print() {

        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << hashTable[i] << ", ";
        }

        cout << endl;
    }
};

int main() {
    DoubleHash myHash(13);

    // Inserciones
    int insertions[] = {115, 12, 87, 66, 123};

    int n1 = sizeof(insertions) / sizeof(insertions[0]);

    for (int i = 0; i < n1; i++) {
        myHash.insert(insertions[i]);
    }

    cout << "Estado de la tabla hash después de las inserciones: ";
    myHash.print();

    // Búsquedas
    int queries[] = {1, 12, 2, 3, 69, 88, 115};

    int n2 = sizeof(queries) / sizeof(queries[0]);

    cout << "\nOperacion de búsqueda después de la inserción:\n";

    for (int i = 0; i < n2; i++) {
        if (myHash.search(queries[i])) {
            cout << queries[i] << " presente" << endl;
        }
    }

    // Eliminaciones
    int deletions[] = {123, 87, 66};

    int n3 = sizeof(deletions) / sizeof(deletions[0]);

    for (int i = 0; i < n3; i++) {
        myHash.erase(deletions[i]);
    }

    cout << "\nEstado de la tabla hash después de eliminar elementos: ";
    myHash.print();

    return 0;
}
