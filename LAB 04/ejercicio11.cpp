#include <iostream>
#include <list>

using namespace std;

int main() {
    list<string> list;
    // Añadir elementos
    list.push_back("Uno, Dos, Tres");
    list.push_back("Cuatro");
    // Mostrar elementos (opcional)
    cout << "Lista: ";
    for (const string& e : list) {
        cout << e << " ";
    }
    cout << endl;

    // Tamaño de la lista
    cout << "El tamaño de la lista es: " << list.size() << endl;

    return 0;
}