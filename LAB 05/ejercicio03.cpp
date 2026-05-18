#include <iostream>

using namespace std;

// Clase Nodo representando un nodo de la lista enlazada
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Clase Pila usando lista enlazada
class Stack {
private:
    Node* head;

public:
    // Constructor
    Stack() {
        head = nullptr;
    }

    // Verificar si la pila está vacía
    bool isEmpty() {
        return head == nullptr;
    }

    // Insertar elemento en la pila
    void push(int new_data) {

        // Crear nuevo nodo
        Node* new_node = new Node(new_data);

        // Verificar si la memoria fue asignada
        if (new_node == nullptr) {
            cout << "\nPila desbordada" << endl;
            return;
        }

        // Enlazar el nuevo nodo al nodo superior actual
        new_node->next = head;

        // Actualizar la cabeza
        head = new_node;
    }

    // Eliminar elemento superior
    void pop() {

        // Verificar si la pila está vacía
        if (isEmpty()) {
            cout << "\nPila desbordada por abajo" << endl;
            return;
        }

        // Nodo temporal
        Node* temp = head;

        // Mover la cabeza al siguiente nodo
        head = head->next;

        // Liberar memoria
        delete temp;
    }

    // Obtener elemento superior
    int peek() {

        if (!isEmpty()) {
            return head->data;
        } else {
            cout << "\nPila está vacía" << endl;
            return -1;
        }
    }

    // Destructor para liberar memoria
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {

    // Crear pila
    Stack st;

    // Agregar elementos
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    // Mostrar elemento superior
    cout << "El elemento en la cima es "
         << st.peek() << endl;

    // Eliminar dos elementos
    cout << "Removiendo dos elementos..." << endl;

    st.pop();
    st.pop();

    // Mostrar nuevo elemento superior
    cout << "Elemento en la cima es "
         << st.peek() << endl;

    return 0;
}