#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // verificar si la cola esta vacia
    bool isempty() {
        return front == nullptr;
    }

    // insertar elementos en la cola
    void enqueue(int new_data) {
        Node* new_node = new Node(new_data);
        // si la cola esta vacia
        if (isempty()) {
            front = rear = new_node;
            printQueue();
            return;
        }
        rear->next = new_node;
        rear = new_node;
        printQueue();
    }
    // eliminar elementos de la cola
    void dequeue() {
        if (isempty()) {
            return;
        }
        
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        printQueue();
    }

    // mostrar cola actual
    void printQueue() {
        if (isempty()) {
            cout << "Cola esta vacia" << endl;
            return;
        }
        Node* temp = front;
        cout << "Cola actual: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    // poner elementos en cola
    q.enqueue(10);
    q.enqueue(20);
    // sacar elementos
    q.dequeue();
    q.dequeue();
    // poner mas elementos
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    // sacar un elemento
    q.dequeue();

    return 0;
}