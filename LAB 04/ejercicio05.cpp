#include <iostream>
#include <list> 

using namespace std;

int main() {
    // Crear una lista enlazada de strings
    list<string> l;

    // Añadir elementos
    l.push_back("Uno");
    l.push_back("Dos");
    l.push_back("Tres");
    l.push_back("Cuatro");
    l.push_back("Cinco");

    // Imprimir la lista
    cout << "Lista: ";
    for (const string& elemento : l) {
        cout << elemento << " ";
    }
    cout << endl;

    return 0;
}
