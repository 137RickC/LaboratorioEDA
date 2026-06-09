#include <iostream>
using namespace std;
// Nodo del BST
class Nodo {
public:
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};
// Clase BST
class BST {
private:
    Nodo* raiz;
    // Inserción recursiva
    Nodo* insertarRec(Nodo* nodo, int valor) {
        if (nodo == nullptr)
            return new Nodo(valor);

        if (valor < nodo->dato)
            nodo->izquierda = insertarRec(nodo->izquierda, valor);
        else if (valor > nodo->dato)
            nodo->derecha = insertarRec(nodo->derecha, valor);

        return nodo;
    }
    // Recorrido Inorden
    void inordenRec(Nodo* nodo) {
        if (nodo != nullptr) {
            inordenRec(nodo->izquierda);
            cout << nodo->dato << " ";
            inordenRec(nodo->derecha);
        }
    }
    // Búsqueda
    bool buscarRec(Nodo* nodo, int valor) {
        if (nodo == nullptr)
            return false;

        if (nodo->dato == valor)
            return true;

        if (valor < nodo->dato)
            return buscarRec(nodo->izquierda, valor);

        return buscarRec(nodo->derecha, valor);
    }
public:
    BST() { raiz = nullptr;}
    void insertar(int valor) { raiz = insertarRec(raiz, valor); }
    void inorden() {
        inordenRec(raiz);
        cout << endl;
    }
    bool buscar(int valor) { return buscarRec(raiz, valor); }
};

int main() {
    BST arbol;

    arbol.insertar(50);
    arbol.insertar(30);
    arbol.insertar(70);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(60);
    arbol.insertar(80);

    cout << "Recorrido Inorden: ";
    arbol.inorden();

    int valor = 60;
    if (arbol.buscar(valor))
        cout << valor << " encontrado en el árbol." << endl;
    else
        cout << valor << " no encontrado." << endl;

    return 0;
}