#include <iostream>
using namespace std;
// Clase Nodo
class Node {
public:

    int data;
    int color; // 1 = RED, 0 = BLACK

    Node* parent;
    Node* left;
    Node* right;
};
// Clase Árbol Red-Black
class RedBlackTree {
private:

    Node* root;
    Node* TNULL;
    // Recorrido PreOrder
    void preOrderHelper(Node* node) {

        if (node != TNULL) {

            cout << node->data << " ";

            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }

    // Recorrido InOrder
    void inOrderHelper(Node* node) {

        if (node != TNULL) {

            inOrderHelper(node->left);

            cout << node->data << " ";

            inOrderHelper(node->right);
        }
    }

    // Recorrido PostOrder
    void postOrderHelper(Node* node) {

        if (node != TNULL) {

            postOrderHelper(node->left);
            postOrderHelper(node->right);

            cout << node->data << " ";
        }
    }

    // Buscar nodo
    Node* searchTreeHelper(Node* node, int key) {

        if (node == TNULL || key == node->data)
            return node;

        if (key < node->data)
            return searchTreeHelper(node->left, key);

        return searchTreeHelper(node->right, key);
    }

    // Balancear inserción
    void fixInsert(Node* k) {

        Node* u;

        while (k->parent->color == 1) {

            // Padre es hijo derecho
            if (k->parent == k->parent->parent->right) {

                u = k->parent->parent->left;

                // Caso tío rojo
                if (u->color == 1) {

                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;

                    k = k->parent->parent;
                }

                else {

                    // Rotación derecha
                    if (k == k->parent->left) {

                        k = k->parent;

                        rightRotate(k);
                    }

                    k->parent->color = 0;
                    k->parent->parent->color = 1;

                    leftRotate(k->parent->parent);
                }
            }

            // Padre es hijo izquierdo
            else {

                u = k->parent->parent->right;

                if (u->color == 1) {

                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;

                    k = k->parent->parent;
                }

                else {

                    if (k == k->parent->right) {

                        k = k->parent;

                        leftRotate(k);
                    }

                    k->parent->color = 0;
                    k->parent->parent->color = 1;

                    rightRotate(k->parent->parent);
                }
            }

            if (k == root)
                break;
        }

        root->color = 0;
    }

    // Balancear eliminación
    void fixDelete(Node* x) {

        Node* s;

        while (x != root && x->color == 0) {

            // x es hijo izquierdo
            if (x == x->parent->left) {

                s = x->parent->right;

                // Hermano rojo
                if (s->color == 1) {

                    s->color = 0;
                    x->parent->color = 1;

                    leftRotate(x->parent);

                    s = x->parent->right;
                }

                // Ambos hijos negros
                if (s->left->color == 0 &&
                    s->right->color == 0) {

                    s->color = 1;

                    x = x->parent;
                }

                else {

                    // Hijo derecho negro
                    if (s->right->color == 0) {

                        s->left->color = 0;
                        s->color = 1;

                        rightRotate(s);

                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->right->color = 0;

                    leftRotate(x->parent);

                    x = root;
                }
            }

            // x es hijo derecho
            else {

                s = x->parent->left;

                if (s->color == 1) {

                    s->color = 0;
                    x->parent->color = 1;

                    rightRotate(x->parent);

                    s = x->parent->left;
                }

                if (s->right->color == 0 &&
                    s->left->color == 0) {

                    s->color = 1;

                    x = x->parent;
                }

                else {

                    if (s->left->color == 0) {

                        s->right->color = 0;
                        s->color = 1;

                        leftRotate(s);

                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->left->color = 0;

                    rightRotate(x->parent);

                    x = root;
                }
            }
        }

        x->color = 0;
    }

    // Reemplazar nodos
    void rbTransplant(Node* u, Node* v) {

        if (u->parent == nullptr)
            root = v;

        else if (u == u->parent->left)
            u->parent->left = v;

        else
            u->parent->right = v;

        v->parent = u->parent;
    }

    // Eliminar nodo auxiliar
    void deleteNodeHelper(Node* node, int key) {

        Node* z = TNULL;
        Node* x;
        Node* y;

        while (node != TNULL) {

            if (node->data == key)
                z = node;

            if (node->data <= key)
                node = node->right;
            else
                node = node->left;
        }

        if (z == TNULL) {

            cout << "No se encontro la clave" << endl;

            return;
        }

        y = z;

        int yOriginalColor = y->color;

        // Sin hijo izquierdo
        if (z->left == TNULL) {

            x = z->right;

            rbTransplant(z, z->right);
        }

        // Sin hijo derecho
        else if (z->right == TNULL) {

            x = z->left;

            rbTransplant(z, z->left);
        }

        // Dos hijos
        else {

            y = minimum(z->right);

            yOriginalColor = y->color;

            x = y->right;

            if (y->parent == z)
                x->parent = y;

            else {

                rbTransplant(y, y->right);

                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);

            y->left = z->left;
            y->left->parent = y;

            y->color = z->color;
        }

        delete z;

        if (yOriginalColor == 0)
            fixDelete(x);
    }

    // Imprimir árbol
    void printHelper(Node* root,
                     string indent,
                     bool last) {

        if (root != TNULL) {

            cout << indent;

            if (last) {

                cout << "R----";

                indent += "   ";
            }

            else {

                cout << "L----";

                indent += "|  ";
            }

            string sColor =
                root->color ? "RED" : "BLACK";

            cout << root->data
                 << "(" << sColor << ")"
                 << endl;

            printHelper(root->left,
                        indent,
                        false);

            printHelper(root->right,
                        indent,
                        true);
        }
    }

public:

    // Constructor
    RedBlackTree() {

        TNULL = new Node;

        TNULL->color = 0;
        TNULL->left = nullptr;
        TNULL->right = nullptr;

        root = TNULL;
    }

    // Rotación izquierda
    void leftRotate(Node* x) {

        Node* y = x->right;

        x->right = y->left;

        if (y->left != TNULL)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;

        else if (x == x->parent->left)
            x->parent->left = y;

        else
            x->parent->right = y;

        y->left = x;

        x->parent = y;
    }

    // Rotación derecha
    void rightRotate(Node* x) {

        Node* y = x->left;

        x->left = y->right;

        if (y->right != TNULL)
            y->right->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;

        else if (x == x->parent->right)
            x->parent->right = y;

        else
            x->parent->left = y;

        y->right = x;

        x->parent = y;
    }

    // Insertar nodo
    void insert(int key) {

        Node* node = new Node;

        node->parent = nullptr;
        node->data = key;

        node->left = TNULL;
        node->right = TNULL;

        node->color = 1;

        Node* y = nullptr;
        Node* x = root;

        while (x != TNULL) {

            y = x;

            if (node->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        node->parent = y;

        if (y == nullptr)
            root = node;

        else if (node->data < y->data)
            y->left = node;

        else
            y->right = node;

        // Nodo raíz
        if (node->parent == nullptr) {

            node->color = 0;

            return;
        }

        // Abuelo nulo
        if (node->parent->parent == nullptr)
            return;

        fixInsert(node);
    }

    // Buscar nodo
    Node* searchTree(int k) {

        return searchTreeHelper(root, k);
    }

    // Buscar mínimo
    Node* minimum(Node* node) {

        while (node->left != TNULL)
            node = node->left;

        return node;
    }

    // Eliminar nodo
    void deleteNode(int data) {

        deleteNodeHelper(root, data);
    }

    // Recorridos
    void preorder() {

        preOrderHelper(root);

        cout << endl;
    }

    void inorder() {

        inOrderHelper(root);

        cout << endl;
    }

    void postorder() {

        postOrderHelper(root);

        cout << endl;
    }

    // Imprimir árbol
    void printTree() {

        if (root)
            printHelper(root, "", true);
    }
};

// Función principal
int main() {

    RedBlackTree bst;

    bst.insert(55);
    bst.insert(40);
    bst.insert(65);
    bst.insert(60);
    bst.insert(75);
    bst.insert(57);

    cout << "Arbol Red-Black:" << endl;

    bst.printTree();

    cout << endl;

    cout << "Recorrido InOrder:" << endl;

    bst.inorder();

    cout << endl;

    // Búsqueda
    int valor = 60;

    Node* encontrado =
        bst.searchTree(valor);

    if (encontrado != nullptr &&
        encontrado->data == valor)

        cout << "Elemento "
             << valor
             << " encontrado"
             << endl;

    else

        cout << "Elemento no encontrado"
             << endl;

    cout << endl;

    // Eliminación
    cout << "Despues de eliminar 40:"
         << endl;

    bst.deleteNode(40);

    bst.printTree();

    return 0;
}