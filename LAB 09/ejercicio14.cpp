#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    // Crear HashSet equivalente en C++
    unordered_set<string> h;
    // Agregar elementos (add en Java → insert en C++)
    h.insert("India");
    h.insert("Australia");
    h.insert("Sur Africa");
    h.insert("India"); // duplicado (se ignora)

    // Mostrar HashSet
    cout << "{ ";
    for (const auto &x : h) {
        cout << x << " ";
    }
    cout << "}" << endl;

    // contains en Java → find en C++
    cout << "\nHashSet contiene India o no: "
         << (h.find("India") != h.end())
         << endl;

    // remove
    h.erase("Australia");

    cout << "\nLista despues de remover Australia: { ";

    for (const auto &x : h) {
        cout << x << " ";
    }
    cout << "}" << endl;
    // Iteración manual (equivalente a Iterator)
    cout << "\nIterando sobre la lista:" << endl;

    for (auto it = h.begin(); it != h.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
