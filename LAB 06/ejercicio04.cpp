#include <iostream>
using namespace std;

// Clase Nodo
class Nodo {
public:
    int key;
    Nodo* left;
    Nodo* right;

    // Constructor
    Nodo(int valor) {
        key = valor;
        left = nullptr;
        right = nullptr;
    }
};

// Clase Árbol Binario de Búsqueda
class ArbolBinarioBusqueda {
private:
    Nodo* root;

    // Recorrido en orden
    void inorder(Nodo* nodo) {
        if (nodo != nullptr) {
            inorder(nodo->left);
            cout << nodo->key << " ";
            inorder(nodo->right);
        }
    }

public:
    // Constructor
    ArbolBinarioBusqueda() {
        root = nullptr;
    }

    // Crear árbol de ejemplo
    void crearArbolEjemplo() {

        //        10
        //       /  \
        //      5    15
        //          /  \
        //         12   18

        root = new Nodo(10);
        root->left = new Nodo(5);
        root->right = new Nodo(15);
        root->right->left = new Nodo(12);
        root->right->right = new Nodo(18);
    }

    // Método para eliminar iterativamente
    void eliminar(int key) {

        Nodo* curr = root;
        Nodo* prev = nullptr;

        // Buscar el nodo a eliminar
        while (curr != nullptr && curr->key != key) {

            prev = curr;

            if (key < curr->key)
                curr = curr->left;
            else
                curr = curr->right;
        }

        // Clave no encontrada
        if (curr == nullptr) {
            cout << "La clave no existe en el arbol." << endl;
            return;
        }

        // CASO 1 y 2:
        // Nodo con cero o un hijo
        if (curr->left == nullptr || curr->right == nullptr) {

            Nodo* newCurr;

            // Si no tiene hijo izquierdo
            if (curr->left == nullptr)
                newCurr = curr->right;
            else
                newCurr = curr->left;

            // Si el nodo eliminado es la raíz
            if (prev == nullptr) {
                root = newCurr;
                delete curr;
                return;
            }

            // Reconectar el padre con el nuevo nodo
            if (curr == prev->left)
                prev->left = newCurr;
            else
                prev->right = newCurr;

            delete curr;
        }

        // CASO 3:
        // Nodo con dos hijos
        else {

            Nodo* p = nullptr;
            Nodo* temp = curr->right;

            // Buscar sucesor inorden
            while (temp->left != nullptr) {
                p = temp;
                temp = temp->left;
            }

            // Reorganizar enlaces
            if (p != nullptr)
                p->left = temp->right;
            else
                curr->right = temp->right;

            // Reemplazar valor
            curr->key = temp->key;

            delete temp;
        }
    }

    // Imprimir en inorden
    void imprimirInorden() {
        inorder(root);
        cout << endl;
    }
};

// Función principal
int main() {

    ArbolBinarioBusqueda abb;

    abb.crearArbolEjemplo();

    cout << "Arbol original (inorden):" << endl;
    abb.imprimirInorden();

    int x = 15;

    cout << "Eliminando el nodo: " << x << endl;

    abb.eliminar(x);

    cout << "Arbol despues de eliminar:" << endl;
    abb.imprimirInorden();

    return 0;
}