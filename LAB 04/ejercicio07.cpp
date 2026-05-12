#include <iostream>
#include <list>

using namespace std;

int main() {
    list<string> ll;

    // Añadir elementos
    ll.push_back("Uno");
    ll.push_back("Tres");

    // Insertar en posición 1
    auto it = ll.begin();
    advance(it, 1); // mover a la posición 1
    ll.insert(it, "Dos");

    // Imprimir la lista
    cout << "Lista: ";
    for (const string& e : ll) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}