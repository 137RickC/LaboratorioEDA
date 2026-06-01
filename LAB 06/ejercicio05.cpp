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
    Nodo(int valor) {
        key = valor;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

// Clase AVL
class AVLTree {

private:
    Nodo* root;

    // Obtener altura
    int height(Nodo* node) {
        if (node == nullptr)
            return 0;

        return node->height;
    }

    // Máximo entre dos números
    int maximo(int a, int b) {
        return (a > b) ? a : b;
    }

    // Rotación derecha
    Nodo* rightRotate(Nodo* node) {

        Nodo* leftChild = node->left;
        Nodo* temp = leftChild->right;

        // Rotación
        leftChild->right = node;
        node->left = temp;

        // Actualizar alturas
        node->height =
            maximo(height(node->left),
                    height(node->right)) + 1;

        leftChild->height =
            maximo(height(leftChild->left),
                    height(leftChild->right)) + 1;

        // Nueva raíz
        return leftChild;
    }

    // Rotación izquierda
    Nodo* leftRotate(Nodo* node) {

        Nodo* rightChild = node->right;
        Nodo* temp = rightChild->left;

        // Rotación
        rightChild->left = node;
        node->right = temp;

        // Actualizar alturas
        node->height =
            maximo(height(node->left),
                    height(node->right)) + 1;

        rightChild->height =
            maximo(height(rightChild->left),
                    height(rightChild->right)) + 1;

        // Nueva raíz
        return rightChild;
    }

    // Obtener factor de balance
    int getBalance(Nodo* node) {

        if (node == nullptr)
            return 0;

        return height(node->left) - height(node->right);
    }

    // Inserción AVL
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

    // Recorrido Preorden
    void preOrder(Nodo* node) {

        if (node != nullptr) {

            cout << node->key << " ";

            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // Recorrido Inorden
    void inOrder(Nodo* node) {

        if (node != nullptr) {

            inOrder(node->left);

            cout << node->key << " ";

            inOrder(node->right);
        }
    }

    // Recorrido Postorden
    void postOrder(Nodo* node) {

        if (node != nullptr) {

            postOrder(node->left);
            postOrder(node->right);

            cout << node->key << " ";
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

    // Método público preorden
    void imprimirPreOrder() {
        preOrder(root);
        cout << endl;
    }

    // Método público inorden
    void imprimirInOrder() {
        inOrder(root);
        cout << endl;
    }

    // Método público postorden
    void imprimirPostOrder() {
        postOrder(root);
        cout << endl;
    }
};

// Función principal
int main() {

    AVLTree tree;

    tree.insertar(10);
    tree.insertar(20);
    tree.insertar(30);
    tree.insertar(40);
    tree.insertar(50);
    tree.insertar(25);

    cout << "Recorrido PreOrder del arbol AVL:" << endl;
    tree.imprimirPreOrder();

    cout << endl;

    cout << "Recorrido InOrder del arbol AVL:" << endl;
    tree.imprimirInOrder();

    cout << endl;

    cout << "Recorrido PostOrder del arbol AVL:" << endl;
    tree.imprimirPostOrder();

    return 0;
}