#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> linkedList;

    // Añadir elementos normales
    linkedList.push_back(1);
    linkedList.push_back(2);
    linkedList.push_back(3);

    // addFirst() -> insertar al inicio
    linkedList.push_front(0);

    // addLast() -> insertar al final
    linkedList.push_back(4);

    // Imprimir la lista
    cout << "LinkedList: ";
    for (int x : linkedList) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}