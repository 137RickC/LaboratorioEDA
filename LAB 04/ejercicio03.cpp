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
    // Método para insertar
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
    // Método para imprimir
    void printList() {
        Node* currNode = head;
        cout << "LinkedList: ";
        while (currNode != nullptr) {
            cout << currNode->data << " ";
            currNode = currNode->next;
        }
        cout << endl;
    }
    // Método para eliminar por posición
    void deleteAtPosition(int index) {
        Node* currNode = head;
        Node* prev = nullptr;

        // CASO 1: eliminar la cabeza
        if (index == 0 && currNode != nullptr) {
            head = currNode->next;
            delete currNode;
            cout << index << " position element deleted" << endl;
            return;
        }
        // CASO 2: recorrer la lista
        int counter = 0;
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
        // CASO 3: índice fuera de rango
        cout << index << " position element not found" << endl;
    }
};
// Función principal
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
    // Imprimir lista inicial
    list.printList();
    // Eliminar posición 0 (cabeza)
    list.deleteAtPosition(0);
    list.printList();
    // Eliminar posición 2 (medio)
    list.deleteAtPosition(2);
    list.printList();
    // Eliminar posición inexistente
    list.deleteAtPosition(10);
    list.printList();

    return 0;
}