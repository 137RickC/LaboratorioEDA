#include <iostream>
using namespace std;
// Clase Nodo
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
    Nodo* insertarRec(Nodo* nodo, int valor) {
        if (nodo == nullptr)
            return new Nodo(valor);
        if (valor < nodo->dato)
            nodo->izquierda = insertarRec(nodo->izquierda, valor);
        else if (valor > nodo->dato)
            nodo->derecha = insertarRec(nodo->derecha, valor);

        return nodo;
    }

public:
    BST() { raiz = nullptr; }

    void insertar(int valor) { raiz = insertarRec(raiz, valor); }

    Nodo* obtenerRaiz() { return raiz; }
};

// Función para comparar árboles
bool sonIguales(Nodo* a, Nodo* b) {
    // Ambos vacíos
    if (a == nullptr && b == nullptr) return true;
    // Uno vacío y otro no
    if (a == nullptr || b == nullptr) return false;
    // Comparar dato y subárboles
    return (a->dato == b->dato) &&
           sonIguales(a->izquierda, b->izquierda) &&
           sonIguales(a->derecha, b->derecha);
}

int main() {
    BST arbol1;
    BST arbol2;
    // Árbol 1
    arbol1.insertar(50);
    arbol1.insertar(30);
    arbol1.insertar(70);
    arbol1.insertar(20);
    arbol1.insertar(40);
    // Árbol 2
    arbol2.insertar(50);
    arbol2.insertar(30);
    arbol2.insertar(70);
    arbol2.insertar(20);
    arbol2.insertar(40);

    if (sonIguales(arbol1.obtenerRaiz(), arbol2.obtenerRaiz()))
        cout << "Los árboles tienen los mismos elementos y estructura." << endl;
    else
        cout << "Los árboles son diferentes." << endl;

    return 0;
}