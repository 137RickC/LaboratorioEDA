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
    // ELIMINAR ÚLTIMO ELEMENTO (equivalente a removeLast)
    if (!list.empty()) {
        int removed = list.back(); // obtener último elemento
        list.pop_back(); // eliminarlo
        cout << "The last element is removed: " << removed << endl;
    }
    // Mostrar lista final
    cout << "Final LinkedList: ";
    for (int x : list) {
        cout << x << " ";
    }
    cout << endl;
    // SEGUNDA ELIMINACIÓN
    if (!list.empty()) {
        int removed = list.back();
        list.pop_back();
        cout << "The last element is removed: " << removed << endl;
    }
    // Mostrar lista final
    cout << "Final LinkedList: ";
    for (int x : list) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}