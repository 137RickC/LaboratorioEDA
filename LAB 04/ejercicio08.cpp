#include <iostream>
#include <list>
using namespace std;

int main() {
    list<string> ll;
    // Añadir elementos
    ll.push_back("Uno");
    ll.push_back("Dos");
    // Insertar "Tres" en posición 1
    auto it = ll.begin();
    advance(it, 1);
    ll.insert(it, "Tres");
    // Mostrar lista inicial
    cout << "Initial LinkedList: ";
    for (const string& e : ll) {
        cout << e << " ";
    }
    cout << endl;
    // CAMBIO DE ELEMENTO (equivalente a set)
    it = ll.begin();
    advance(it, 1); // posición 1
    if (it != ll.end()) {
        *it = "Cuatro"; // modificar valor
    }
    // Mostrar lista actualizada
    cout << "Updated LinkedList: ";
    for (const string& e : ll) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}