#include <iostream>
using namespace std;
// Clase LinkedList
class LinkedList {

public:
    // Definición del nodo
    class Node {
    public:
        int data;
        Node* next;
        // Constructor
        Node(int d) {
            data = d;
            next = nullptr;
        }
    };
    Node* head; // cabeza de la lista
    // Constructor de LinkedList
    LinkedList() {
        head = nullptr;
    }
    // Método para insertar un nodo al final
    void insert(int data) {
        Node* new_node = new Node(data);

        // Si la lista está vacía
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* last = head;
            // Recorrer hasta el último nodo
            while (last->next != nullptr) {
                last = last->next;
            }
            // Insertar al final
            last->next = new_node;
        }
    }
    // Método para imprimir la lista
    void printList() {
        Node* currNode = head;
        cout << "LinkedList: ";
        while (currNode != nullptr) {
            cout << currNode->data << " ";
            currNode = currNode->next;
        }
        cout << endl;
    }
};
// Función principal
int main() {
    LinkedList list;

    // Inserción de elementos
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);
    list.insert(8);

    // Imprimir la lista
    list.printList();

    return 0;
}