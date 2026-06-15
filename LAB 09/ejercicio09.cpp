#include <iostream>


using namespace std;


// Nodo de la lista doblemente enlazada
class DoublyLinkedListNode {
public:
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;


    // Constructor
    DoublyLinkedListNode(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};


// Tabla Hash con encadenamiento usando listas doblemente enlazadas
class HashTableChainingDoublyLinkedList {


private:
    DoublyLinkedListNode** hashTable;
    int tableSize;
    int size;


    // Función hash
    int hash(int x) {


        int hashValue = x % tableSize;


        if (hashValue < 0)
            hashValue += tableSize;


        return hashValue;
    }


public:


    // Constructor
    HashTableChainingDoublyLinkedList(int hashTableSize) {


        tableSize = hashTableSize;
        size = 0;


        hashTable = new DoublyLinkedListNode*[tableSize];


        for (int i = 0; i < tableSize; i++)
            hashTable[i] = nullptr;
    }


    // Verificar si está vacía
    bool isEmpty() {
        return size == 0;
    }


    // Obtener tamaño
    int getSize() {
        return size;
    }


    // Vaciar tabla
    void clear() {


        for (int i = 0; i < tableSize; i++) {


            DoublyLinkedListNode* current = hashTable[i];


            while (current != nullptr) {


                DoublyLinkedListNode* temp = current;
                current = current->next;


                delete temp;
            }


            hashTable[i] = nullptr;
        }


        size = 0;
    }


    // Insertar elemento
    void insert(int value) {


        size++;


        int position = hash(value);


        DoublyLinkedListNode* node =
            new DoublyLinkedListNode(value);


        DoublyLinkedListNode* start =
            hashTable[position];


        if (hashTable[position] == nullptr) {


            hashTable[position] = node;
        }
        else {


            node->next = start;
            start->prev = node;


            hashTable[position] = node;
        }
    }


    // Eliminar elemento
    void remove(int value) {


        try {


            int position = hash(value);


            DoublyLinkedListNode* start =
                hashTable[position];


            if (start == nullptr) {
                throw runtime_error("No encontrado");
            }


            DoublyLinkedListNode* end = start;


            // Caso: elemento al inicio
            if (start->data == value) {


                size--;


                if (start->next == nullptr) {


                    delete start;
                    hashTable[position] = nullptr;


                    return;
                }


                start = start->next;


                start->prev = nullptr;


                delete hashTable[position];


                hashTable[position] = start;


                return;
            }


            // Buscar elemento
            while (end->next != nullptr &&
                   end->next->data != value) {


                end = end->next;
            }


            if (end->next == nullptr) {


                cout << "\nElemento no encontrado\n";
                return;
            }


            size--;


            DoublyLinkedListNode* temp = end->next;


            if (temp->next == nullptr) {


                end->next = nullptr;


                delete temp;


                return;
            }


            temp->next->prev = end;


            end->next = temp->next;


            delete temp;
        }
        catch (...) {


            cout << "\nElemento no encontrado\n";
        }
    }


    // Imprimir tabla hash
    void printHashTable() {


        cout << endl;


        for (int i = 0; i < tableSize; i++) {


            cout << "Para " << i << ": ";


            DoublyLinkedListNode* start =
                hashTable[i];


            while (start != nullptr) {


                cout << start->data << " ";


                start = start->next;
            }


            cout << endl;
        }
    }


    // Destructor
    ~HashTableChainingDoublyLinkedList() {


        clear();


        delete[] hashTable;
    }
};


// Programa principal
int main() {


    HashTableChainingDoublyLinkedList hashTab(5);


    hashTab.insert(99);
    hashTab.insert(23);
    hashTab.insert(36);
    hashTab.insert(47);
    hashTab.insert(80);


    hashTab.printHashTable();


    hashTab.insert(92);
    hashTab.insert(49);


    hashTab.printHashTable();


    hashTab.remove(99);


    hashTab.printHashTable();


    hashTab.clear();


    hashTab.printHashTable();


    cout << boolalpha
         << hashTab.isEmpty()
         << endl;


    return 0;
}
