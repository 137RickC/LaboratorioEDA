#include <iostream>
using namespace std;

// Clase Nodo
class Nodo {
public:
    int key;
    int height;
    Nodo* left;
    Nodo* right;

    // Constructor
    Nodo(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// Clase Árbol AVL
class AVLTree {

private:
    Nodo* root;

    // Obtener altura del árbol
    int height(Nodo* N) {

        if (N == nullptr)
            return 0;

        return N->height;
    }

    // Obtener máximo entre dos números
    int maximo(int a, int b) {
        return (a > b) ? a : b;
    }

    // Rotación derecha
    Nodo* rightRotate(Nodo* y) {

        Nodo* x = y->left;
        Nodo* T2 = x->right;

        // Realizar rotación
        x->right = y;
        y->left = T2;

        // Actualizar alturas
        y->height =
            1 + maximo(height(y->left),
                        height(y->right));

        x->height =
            1 + maximo(height(x->left),
                        height(x->right));

        // Nueva raíz
        return x;
    }

    // Rotación izquierda
    Nodo* leftRotate(Nodo* x) {

        Nodo* y = x->right;
        Nodo* T2 = y->left;

        // Realizar rotación
        y->left = x;
        x->right = T2;

        // Actualizar alturas
        x->height =
            1 + maximo(height(x->left),
                        height(x->right));

        y->height =
            1 + maximo(height(y->left),
                        height(y->right));

        // Nueva raíz
        return y;
    }

    // Obtener factor de balance
    int getBalance(Nodo* N) {

        if (N == nullptr)
            return 0;

        return height(N->left) - height(N->right);
    }

    // Inserción recursiva AVL
    Nodo* insert(Nodo* node, int key) {

        // Inserción normal BST
        if (node == nullptr)
            return new Nodo(key);

        if (key < node->key)
            node->left = insert(node->left, key);

        else if (key > node->key)
            node->right = insert(node->right, key);

        else
            return node;

        // Actualizar altura
        node->height =
            1 + maximo(height(node->left),
                        height(node->right));

        // Obtener balance
        int balance = getBalance(node);

        // Caso Izquierda-Izquierda
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Caso Derecha-Derecha
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Caso Izquierda-Derecha
        if (balance > 1 && key > node->left->key) {

            node->left = leftRotate(node->left);

            return rightRotate(node);
        }

        // Caso Derecha-Izquierda
        if (balance < -1 && key < node->right->key) {

            node->right = rightRotate(node->right);

            return leftRotate(node);
        }

        return node;
    }

    // Recorrido PreOrder
    void preOrder(Nodo* root) {

        if (root != nullptr) {

            cout << root->key << " ";

            preOrder(root->left);
            preOrder(root->right);
        }
    }

public:

    // Constructor
    AVLTree() {
        root = nullptr;
    }

    // Método público insertar
    void insertar(int key) {
        root = insert(root, key);
    }

    // Método público PreOrder
    void imprimirPreOrder() {
        preOrder(root);
        cout << endl;
    }
};

// Función principal
int main() {

    AVLTree tree;

    // Construcción del árbol AVL
    tree.insertar(10);
    tree.insertar(20);
    tree.insertar(30);
    tree.insertar(40);
    tree.insertar(50);
    tree.insertar(25);

    /*
            Árbol AVL resultante:

                  30
                 /  \
               20    40
              / \      \
            10  25      50
    */

    cout << "Recorrido PreOrder del arbol AVL:" << endl;

    tree.imprimirPreOrder();

    return 0;
}