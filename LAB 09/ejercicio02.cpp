#include <iostream>
using namespace std;
// Nodo de la tabla hash
class HashNode {
public:
    int key;
    int value;

    // Constructor
    HashNode(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class HashMap {
private:
    HashNode** arr;   // Arreglo de punteros a nodos
    int capacity;
    int size;
    HashNode* dummy;
public:
    // Constructor
    HashMap() {
        capacity = 20;
        size = 0;

        arr = new HashNode*[capacity];

        for (int i = 0; i < capacity; i++) {
            arr[i] = nullptr;
        }
        // Nodo especial para marcar eliminaciones
        dummy = new HashNode(-1, -1);
    }
    // Función hash
    int hashCode(int key) { return key % capacity;  }
    // Insertar clave y valor
    void insertNode(int key, int value) {

        HashNode* temp = new HashNode(key, value);

        int hashIndex = hashCode(key);

        while (arr[hashIndex] != nullptr &&
               arr[hashIndex]->key != key &&
               arr[hashIndex]->key != -1) {

            hashIndex++;
            hashIndex %= capacity;
        }

        if (arr[hashIndex] == nullptr ||
            arr[hashIndex]->key == -1) {
            size++;
        }

        arr[hashIndex] = temp;
    }

    // Eliminar una clave
    int deleteNode(int key) {
        int hashIndex = hashCode(key);

        while (arr[hashIndex] != nullptr) {

            if (arr[hashIndex]->key == key) {
                HashNode* temp = arr[hashIndex];
                arr[hashIndex] = dummy;
                size--;

                return temp->value;
            }

            hashIndex++;
            hashIndex %= capacity;
        }
        return -1;
    }

    // Obtener valor asociado a una clave
    int get(int key) {
        int hashIndex = hashCode(key);
        int counter = 0;

        while (arr[hashIndex] != nullptr) {

            if (counter++ > capacity) {
                return -1;
            }

            if (arr[hashIndex]->key == key) {
                return arr[hashIndex]->value;
            }
            hashIndex++;
            hashIndex %= capacity;
        }
        return -1;
    }

    // Tamaño actual de la tabla
    int sizeofMap() { return size; }
    // Verificar si está vacía
    bool isEmpty() { return size == 0; }
    // Mostrar contenido
    void display() {
        cout << "Clave  Valor" << endl;

        for (int i = 0; i < capacity; i++) {
            if (arr[i] != nullptr &&
                arr[i]->key != -1) {
                cout << arr[i]->key
                     << "      "
                     << arr[i]->value
                     << endl;
            }
        }
    }
    // Destructor
    ~HashMap() {
        for (int i = 0; i < capacity; i++) {

            if (arr[i] != nullptr &&
                arr[i] != dummy) {

                delete arr[i];
            }
        }
        delete dummy;
        delete[] arr;
    }
};
// Programa principal
int main() {
    HashMap h;

    h.insertNode(1, 1);
    h.insertNode(2, 2);

    // Actualiza la clave 2 con el valor 3
    h.insertNode(2, 3);
    h.display();

    cout << "\nTamaño: "
         << h.sizeofMap() << endl;

    cout << "Valor eliminado: "
         << h.deleteNode(2) << endl;

    cout << "Tamaño después de eliminar: "
         << h.sizeofMap() << endl;

    cout << "¿Está vacía?: "
         << (h.isEmpty() ? "Sí" : "No")
         << endl;

    cout << "Buscar clave 2: "
         << h.get(2) << endl;

    return 0;
}