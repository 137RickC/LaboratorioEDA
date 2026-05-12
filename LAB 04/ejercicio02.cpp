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
    // Método para eliminar por valor (key)
    void deleteByKey(int key) {
        Node* currNode = head;
        Node* prev = nullptr;

        // CASO 1: El nodo a eliminar es la cabeza
        if (currNode != nullptr && currNode->data == key) {
            head = currNode->next;
            delete currNode;
            cout << key << " found and deleted" << endl;
            return;
        }
        // CASO 2: Buscar el nodo en la lista
        while (currNode != nullptr && currNode->data != key) {
            prev = currNode;
            currNode = currNode->next;
        }
        // Si se encontró el nodo
        if (currNode != nullptr) {
            prev->next = currNode->next;
            delete currNode;
            cout << key << " found and deleted" << endl;
        } else {
            // CASO 3: No encontrado
            cout << key << " not found" << endl;
        }
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
    // Eliminar cabeza
    list.deleteByKey(1);
    list.printList();
    // Eliminar elemento del medio
    list.deleteByKey(4);
    list.printList();
    // Intentar eliminar un elemento que no existe
    list.deleteByKey(10);
    list.printList();
    return 0;
}
