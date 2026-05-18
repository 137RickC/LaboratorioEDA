#include <iostream>
using namespace std;

class LinkedList {
public:
    // Clase Nodo
    class Node {
    public:
        int data;
        Node* next;
        Node(int d) {
            data = d;
            next = nullptr;
        }
    };
    Node* head;
    // Constructor
    LinkedList() {
        head = nullptr;
    }
    //INSERCIÓN 
    void insert(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* last = head;
            while (last->next != nullptr) {
                last = last->next;
            }
            last->next = new_node;
        }
    }
    //RECORRIDO
    void printList() {
        Node* currNode = head;
        cout << "\nLinkedList: ";
        while (currNode != nullptr) {
            cout << currNode->data << " ";
            currNode = currNode->next;
        }
        cout << "\n" << endl;
    }
    //BORRADO POR DATO
    void deleteByKey(int key) {
        Node* currNode = head;
        Node* prev = nullptr;

        // Caso 1: cabeza
        if (currNode != nullptr && currNode->data == key) {
            head = currNode->next;
            delete currNode;
            cout << key << " found and deleted" << endl;
            return;
        }

        // Caso 2: buscar en la lista
        while (currNode != nullptr && currNode->data != key) {
            prev = currNode;
            currNode = currNode->next;
        }

        if (currNode != nullptr) {
            prev->next = currNode->next;
            delete currNode;
            cout << key << " found and deleted" << endl;
        } else {
            // Caso 3: no encontrado
            cout << key << " not found" << endl;
        }
    }
    //BORRADO POR POSICIÓN
    void deleteAtPosition(int index) {
        Node* currNode = head;
        Node* prev = nullptr;

        // Caso 1: cabeza
        if (index == 0 && currNode != nullptr) {
            head = currNode->next;
            delete currNode;
            cout << index << " position element deleted" << endl;
            return;
        }

        int counter = 0;
        // Caso 2: recorrer lista
        while (currNode != nullptr) {
            if (counter == index) {
                prev->next = currNode->next;
                delete currNode;
                cout << index << " position element deleted" << endl;
                return;
            } else {
                prev = currNode;
                currNode = currNode->next;
                counter++;
            }
        }
        // Caso 3: índice inválido
        cout << index << " position element not found" << endl;
    }
};
//FUNCIÓN PRINCIPAL
int main() {
    LinkedList list;

    // Inserción
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);
    list.insert(8);

    // Mostrar lista inicial
    list.printList();
    // ELIMINACIÓN POR DATO 
    list.deleteByKey(1); // cabeza
    list.printList();

    list.deleteByKey(4); // medio
    list.printList();

    list.deleteByKey(10); // no existe
    list.printList();
    
    //  ELIMINACIÓN POR POSICIÓN 
    list.deleteAtPosition(0); // cabeza
    list.printList();

    list.deleteAtPosition(2); // medio
    list.printList();

    list.deleteAtPosition(10); // no existe
    list.printList();

    return 0;
}