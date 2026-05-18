#include <iostream>
#include <queue>
using namespace std;

// Cola global
queue<int> q;

// Verificar si la cola está vacía
bool isEmpty() {
    return q.empty();
}

// Insertar elementos
void qEnqueue(int data) {
    q.push(data);
}

// Eliminar elementos
void qDequeue() {

    if (isEmpty()) {
        return;
    }

    q.pop();
}

// Obtener el frente
int getFront() {

    if (isEmpty()) {
        return -1;
    }

    return q.front();
}

// Obtener el último elemento
int getRear() {

    if (isEmpty()) {
        return -1;
    }

    return q.back();
}

int main() {

    qEnqueue(1);
    qEnqueue(8);
    qEnqueue(3);
    qEnqueue(6);
    qEnqueue(2);

    // Mostrar cola
    if (!isEmpty()) {

        cout << "Cola después de la operación: ";

        // Copia temporal para recorrer
        queue<int> temp = q;

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }

    cout << "Al frente: " << getFront() << endl;
    cout << "Atras: " << getRear() << endl;

    cout << "Tamaño de la cola: "
         << q.size() << endl;

    qDequeue();

    cout << "La cola esta vacia? "
         << (isEmpty() ? "Si" : "No") << endl;

    return 0;
}