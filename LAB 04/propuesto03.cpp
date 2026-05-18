#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

int main() {
    Nodo* inicio = NULL;
    Nodo* nuevo;
    Nodo* aux;
    for (int i = 1; i <= 10; i++) {
        nuevo = new Nodo();
        nuevo->dato = i;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
        if (inicio == NULL) {
            inicio = nuevo;
        } else {
            aux = inicio;
            while (aux->siguiente != NULL) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
            nuevo->anterior = aux;
        }
    }
    cout << "Lista doblemente enlazada:" << endl;
    aux = inicio;
    
    while (aux != NULL) {
        cout << aux->dato << " ";
        aux = aux->siguiente;
    }
    return 0;
}