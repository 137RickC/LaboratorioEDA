#include <iostream>
using namespace std;
// Clase Nodo
class Nodo {
public:
    int key;
    Nodo* left;
    Nodo* right;

    Nodo(int item) {
        key = item;
        left = nullptr;
        right = nullptr;
    }
};
// Clase Árbol Binario de Búsqueda
class ArbolBinarioBusqueda {
private:
    Nodo* root;

    Nodo* insertarRec(Nodo* nodo, int key) {
        if (nodo == nullptr)
            return new Nodo(key);
        if (key < nodo->key)
            nodo->left = insertarRec(nodo->left, key);
        else if (key > nodo->key)
            nodo->right = insertarRec(nodo->right, key);

        return nodo;
    }
public:
    ArbolBinarioBusqueda() {
        root = nullptr;
    }
    void insertar(int key) {
        root = insertarRec(root, key);
    }
    int segundoMayor() {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            cout << "El árbol debe tener al menos dos nodos." << endl;
            return -1;
        }
        Nodo* actual = root;
        Nodo* padre = nullptr;
        // Buscar el mayor elemento
        while (actual->right != nullptr) {
            padre = actual;
            actual = actual->right;
        }
        // Caso 1: el mayor tiene subárbol izquierdo
        if (actual->left != nullptr) {
            Nodo* temp = actual->left;
            while (temp->right != nullptr)
                temp = temp->right;
            return temp->key;
        }
        // Caso 2: el segundo mayor es el padre
        return padre->key;
    }
};
int main() {
    ArbolBinarioBusqueda arbol;

    arbol.insertar(50);
    arbol.insertar(30);
    arbol.insertar(70);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(60);
    arbol.insertar(80);

    cout << "Segundo valor más grande: "
         << arbol.segundoMayor() << endl;

    return 0;
}