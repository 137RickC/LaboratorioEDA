#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> list;

    // Añadir elementos
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    // Mostrar lista inicial
    cout << "LinkedList: ";
    for (int x : list) {
        cout << x << " ";
    }
    cout << endl;
    // Eliminar el primer elemento (equivalente a removeFirst)
    if (!list.empty()) {
        int removed = list.front(); // obtener primer elemento
        list.pop_front(); // eliminarlo
        cout << "El primer elemento removido es: " << removed << endl;
    }
    // Mostrar lista final
    cout << "Final LinkedList: ";
    for (int x : list) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}