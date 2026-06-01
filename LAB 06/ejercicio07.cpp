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

// Clase AVL
class AVLTree {

private:
    Nodo* root;

    // Obtener altura
    int height(Nodo* N) {

        if (N == nullptr)
            return 0;

        return N->height;
    }

    // Máximo entre dos números
    int maximo(int a, int b) {
        return (a > b) ? a : b;
    }

    // Rotación derecha
    Nodo* rightRotate(Nodo* y) {

        Nodo* x = y->left;
        Nodo* T2 = x->right;

        // Rotación
        x->right = y;
        y->left = T2;

        // Actualizar alturas
        y->height =
            maximo(height(y->left),
                    height(y->right)) + 1;

        x->height =
            maximo(height(x->left),
                    height(x->right)) + 1;

        return x;
    }

    // Rotación izquierda
    Nodo* leftRotate(Nodo* x) {

        Nodo* y = x->right;
        Nodo* T2 = y->left;

        // Rotación
        y->left = x;
        x->right = T2;

        // Actualizar alturas
        x->height =
            maximo(height(x->left),
                    height(x->right)) + 1;

        y->height =
            maximo(height(y->left),
                    height(y->right)) + 1;

        return y;
    }

    // Obtener factor de balance
    int getBalance(Nodo* N) {

        if (N == nullptr)
            return 0;

        return height(N->left) - height(N->right);
    }

    // Inserción AVL
    Nodo* insert(Nodo* node, int key) {

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

        int balance = getBalance(node);

        // Casos de balanceo
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key) {

            node->left = leftRotate(node->left);

            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {

            node->right = rightRotate(node->right);

            return leftRotate(node);
        }

        return node;
    }

    // Buscar nodo mínimo
    Nodo* minValueNode(Nodo* node) {

        Nodo* current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    // Eliminación AVL
    Nodo* deleteNode(Nodo* root, int key) {

        // Eliminación BST normal
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);

        else if (key > root->key)
            root->right = deleteNode(root->right, key);

        else {

            // Nodo con uno o cero hijos
            if ((root->left == nullptr) ||
                (root->right == nullptr)) {

                Nodo* temp;

                if (root->left != nullptr)
                    temp = root->left;
                else
                    temp = root->right;

                // Sin hijos
                if (temp == nullptr) {

                    temp = root;
                    root = nullptr;
                }

                else {

                    // Un hijo
                    *root = *temp;
                }

                delete temp;
            }

            else {

                // Nodo con dos hijos
                Nodo* temp = minValueNode(root->right);

                root->key = temp->key;

                root->right =
                    deleteNode(root->right, temp->key);
            }
        }

        // Si el árbol quedó vacío
        if (root == nullptr)
            return root;

        // Actualizar altura
        root->height =
            1 + maximo(height(root->left),
                        height(root->right));

        // Balancear
        int balance = getBalance(root);

        // Caso Izquierda-Izquierda
        if (balance > 1 &&
            getBalance(root->left) >= 0)

            return rightRotate(root);

        // Caso Izquierda-Derecha
        if (balance > 1 &&
            getBalance(root->left) < 0) {

            root->left = leftRotate(root->left);

            return rightRotate(root);
        }

        // Caso Derecha-Derecha
        if (balance < -1 &&
            getBalance(root->right) <= 0)

            return leftRotate(root);

        // Caso Derecha-Izquierda
        if (balance < -1 &&
            getBalance(root->right) > 0) {

            root->right = rightRotate(root->right);

            return leftRotate(root);
        }

        return root;
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

    // Método público eliminar
    void eliminar(int key) {
        root = deleteNode(root, key);
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
    tree.insertar(9);
    tree.insertar(5);
    tree.insertar(10);
    tree.insertar(0);
    tree.insertar(6);
    tree.insertar(11);
    tree.insertar(-1);
    tree.insertar(1);
    tree.insertar(2);

    cout << "Recorrido PreOrder del arbol AVL construido:" << endl;

    tree.imprimirPreOrder();

    // Eliminar nodo
    tree.eliminar(10);

    cout << endl;

    cout << "Recorrido PreOrder despues de eliminar 10:" << endl;

    tree.imprimirPreOrder();

    return 0;
}