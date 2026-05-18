#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

int main() {
    Nodo* inicio = NULL;
    Nodo* nuevo;
    Nodo* aux;
    for (int i = 1; i <= 12; i++) {
        nuevo = new Nodo();
        nuevo->dato = i;
        if (inicio == NULL) {
            inicio = nuevo;
            nuevo->siguiente = inicio;
        } else {
            aux = inicio;
            while (aux->siguiente != inicio) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
            nuevo->siguiente = inicio;
        }
    }
    cout << "Lista circular:" << endl;
    aux = inicio;

    if (inicio != NULL) {
        do {
            cout << aux->dato << " ";
            aux = aux->siguiente;
        } while (aux != inicio);
    }
    return 0;
}   