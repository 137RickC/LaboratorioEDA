#include <iostream>
using namespace std;

class Nodo {
public:
    int dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(int valor) {
        dato = valor;
        siguiente = NULL;
        anterior = NULL;
    }
};

class ListaDoble {
private:
    Nodo* inicio;

public:
    ListaDoble() {
        inicio = NULL;
    }

    void insertar(int valor) {
        Nodo* nuevo = new Nodo(valor);

        if (inicio == NULL) {
            inicio = nuevo;
        } else {
            Nodo* aux = inicio;

            while (aux->siguiente != NULL) {
                aux = aux->siguiente;
            }

            aux->siguiente = nuevo;
            nuevo->anterior = aux;
        }
    }
    void mostrar() {
        Nodo* aux = inicio;

        while (aux != NULL) {
            cout << aux->dato << " ";
            aux = aux->siguiente;
        }
    }
};

int main() {

    ListaDoble lista;

    for (int i = 1; i <= 10; i++) {
        lista.insertar(i);
    }

    cout << "Lista doblemente enlazada:" << endl;
    lista.mostrar();

    return 0;
}