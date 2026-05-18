#include <iostream>
#include <list>
using namespace std;

int main() {
    list<string> ll;

    // Añadir elementos
    ll.push_back("Uno");
    ll.push_back("Dos");
    // Insertar en posición 1
    auto it = ll.begin();
    advance(it, 1);
    ll.insert(it, "Tres");
    //RECORRIDO TIPO "ÍNDICE" (simulado)
    cout << "Recorrido tipo indice: ";
    for (int i = 0; i < ll.size(); i++) {
        auto it2 = ll.begin();
        advance(it2, i); // avanzar hasta la posición i
        cout << *it2 << " ";
    }
    cout << endl;
    //RECORRIDO FOR-EACH 
    cout << "Recorrido for-each: ";
    for (const string& str : ll) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}