#include <iostream>
using namespace std;
// Clase Árbol Red-Black
class RedBlackTree {

private:
    // Clase Nodo
    class Nodo {
    public:
        int data;
        char colour; // 'R' = Rojo, 'B' = Negro

        Nodo* left;
        Nodo* right;
        Nodo* parent;

        // Constructor
        Nodo(int value) {

            data = value;
            colour = 'R';

            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }
    };

    Nodo* root;
    // Banderas de rotación
    bool ll = false;
    bool rr = false;
    bool lr = false;
    bool rl = false;
    // Rotación izquierda
    Nodo* rotateLeft(Nodo* node) {

        Nodo* x = node->right;
        Nodo* y = x->left;

        x->left = node;
        node->right = y;

        node->parent = x;

        if (y != nullptr)
            y->parent = node;

        return x;
    }
    // Rotación derecha
    Nodo* rotateRight(Nodo* node) {

        Nodo* x = node->left;
        Nodo* y = x->right;

        x->right = node;
        node->left = y;

        node->parent = x;

        if (y != nullptr)
            y->parent = node;

        return x;
    }

    // Función auxiliar de inserción
    Nodo* insertHelp(Nodo* root, int data) {

        bool f = false;

        // Inserción BST normal
        if (root == nullptr)
            return new Nodo(data);

        else if (data < root->data) {

            root->left = insertHelp(root->left, data);

            root->left->parent = root;

            if (root != this->root) {

                if (root->colour == 'R' &&
                    root->left->colour == 'R')

                    f = true;
            }
        }

        else {

            root->right = insertHelp(root->right, data);

            root->right->parent = root;

            if (root != this->root) {

                if (root->colour == 'R' &&
                    root->right->colour == 'R')

                    f = true;
            }
        }

        // Rotaciones
        if (this->ll) {

            root = rotateLeft(root);

            root->colour = 'B';
            root->left->colour = 'R';

            this->ll = false;
        }

        else if (this->rr) {

            root = rotateRight(root);

            root->colour = 'B';
            root->right->colour = 'R';

            this->rr = false;
        }

        else if (this->rl) {

            root->right = rotateRight(root->right);

            root->right->parent = root;

            root = rotateLeft(root);

            root->colour = 'B';
            root->left->colour = 'R';

            this->rl = false;
        }

        else if (this->lr) {

            root->left = rotateLeft(root->left);

            root->left->parent = root;

            root = rotateRight(root);

            root->colour = 'B';
            root->right->colour = 'R';

            this->lr = false;
        }

        // Resolver conflicto rojo-rojo
        if (f) {

            // Nodo actual es hijo derecho
            if (root->parent->right == root) {

                // Tío negro o nulo
                if (root->parent->left == nullptr ||
                    root->parent->left->colour == 'B') {

                    if (root->left != nullptr &&
                        root->left->colour == 'R')

                        this->rl = true;

                    else if (root->right != nullptr &&
                             root->right->colour == 'R')

                        this->ll = true;
                }

                else {

                    root->parent->left->colour = 'B';
                    root->colour = 'B';

                    if (root->parent != this->root)
                        root->parent->colour = 'R';
                }
            }

            // Nodo actual es hijo izquierdo
            else {

                if (root->parent->right == nullptr ||
                    root->parent->right->colour == 'B') {

                    if (root->left != nullptr &&
                        root->left->colour == 'R')

                        this->rr = true;

                    else if (root->right != nullptr &&
                             root->right->colour == 'R')

                        this->lr = true;
                }

                else {

                    root->parent->right->colour = 'B';
                    root->colour = 'B';

                    if (root->parent != this->root)
                        root->parent->colour = 'R';
                }
            }

            f = false;
        }

        return root;
    }

    // Recorrido InOrder
    void inorderTraversalHelper(Nodo* node) {

        if (node != nullptr) {

            inorderTraversalHelper(node->left);

            cout << node->data << " ";

            inorderTraversalHelper(node->right);
        }
    }

    // Imprimir árbol visualmente
    void printTreeHelper(Nodo* root, int space) {

        if (root != nullptr) {

            space += 10;

            printTreeHelper(root->right, space);

            cout << endl;

            for (int i = 10; i < space; i++)
                cout << " ";

            cout << root->data
                 << "(" << root->colour << ")";

            cout << endl;

            printTreeHelper(root->left, space);
        }
    }

public:
    // Constructor
    RedBlackTree() {
        root = nullptr;
    }
    // Método insertar
    void insert(int data) {

        if (root == nullptr) {

            root = new Nodo(data);

            root->colour = 'B';
        }

        else {

            root = insertHelp(root, data);

            root->colour = 'B';
        }
    }

    // Método recorrido inorder
    void inorderTraversal() {
        inorderTraversalHelper(root);
        cout << endl;
    }

    // Método imprimir árbol
    void printTree() { printTreeHelper(root, 0); }
};

// Función principal
int main() {

    RedBlackTree tree;

    int arr[] = {1,4,6,3,5,7,8,2,9};

    for (int i = 0; i < 9; i++) {

        tree.insert(arr[i]);

        cout << "Recorrido InOrder despues de insertar "
             << arr[i] << ":" << endl;

        tree.inorderTraversal();
        cout << endl;
    }

    cout << "Arbol Red-Black final:" << endl;
    tree.printTree();

    return 0;
}