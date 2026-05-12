#include <iostream>
#include <list>

using namespace std;

int main() {
    list<string> ll;

    // ===== AÑADIR ELEMENTOS =====
    ll.push_back("A"); // equivalente a add()
    ll.push_back("B");
    ll.push_back("C"); // addLast()
    ll.push_front("D"); // addFirst()

    // Insertar en posición específica (posición 2)
    auto it = ll.begin();
    advance(it, 2); // mover el iterador a la posición 2
    ll.insert(it, "E");

    // Mostrar lista
    cout << "Lista inicial: ";
    for (const string& e : ll) {
        cout << e << " ";
    }
    cout << endl;

    // ===== ELIMINACIONES =====
    // Eliminar por valor
    ll.remove("B");

    // Eliminar por posición (posición 3)
    it = ll.begin();
    advance(it, 3);
    if (it != ll.end()) {
        ll.erase(it);
    }

    // Eliminar primero y último
    ll.pop_front();
    ll.pop_back();

    // Mostrar lista final
    cout << "Lista final: ";
    for (const string& e : ll) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}