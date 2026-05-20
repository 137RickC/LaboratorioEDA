#include <iostream>
#include <queue>
using namespace std;

class MyQueue {
private:
    queue<int> q;

public:
    // Verificar si la cola está vacía
    bool isEmpty() { return q.empty(); }
    // Insertar elementos
    void enqueue(int x) { q.push(x); }
    // Eliminar elementos
    void dequeue() { if (!isEmpty()) { q.pop(); } }
    // Obtener el frente
    int getFront() { return isEmpty() ? -1 : q.front(); }

    // Mostrar la cola
    void display() {
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    MyQueue q;
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.getFront() << endl;

    q.dequeue();

    q.enqueue(4);

    q.display();

    return 0;
}