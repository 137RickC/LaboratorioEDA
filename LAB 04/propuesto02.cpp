#include <iostream>
using namespace std;

class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) {
        dato = valor;
        siguiente = NULL;
    }
};

class ListaCircular {
private:
    Nodo* inicio;

public:
    ListaCircular() {
        inicio = NULL;
    }

    void insertar(int valor) {

        Nodo* nuevo = new Nodo(valor);
        if (inicio == NULL) {
            inicio = nuevo;
            nuevo->siguiente = inicio;
        } else {

            Nodo* aux = inicio;
            while (aux->siguiente != inicio) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
            nuevo->siguiente = inicio;
        }
    }

    void mostrar() {

        Nodo* aux = inicio;
        if (inicio != NULL) {
            do {
                cout << aux->dato << " ";
                aux = aux->siguiente;
            } while (aux != inicio);
        }
    }
};

int main() {

    ListaCircular lista;

    for (int i = 1; i <= 12; i++) {
        lista.insertar(i);
    }

    cout << "Lista circular:" << endl;
    lista.mostrar();

    return 0;
}