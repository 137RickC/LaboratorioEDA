#include <iostream>
#include <queue>

using namespace std;

enum COLOR { RED, BLACK };

// Clase Nodo
class Node {

public:
    int val;
    COLOR color;

    Node *left, *right, *parent;

    Node(int val) {

        this->val = val;

        parent = left = right = nullptr;

        // Nodo rojo al insertar
        color = RED;
    }

    // Retorna el tío
    Node* uncle() {

        if (parent == nullptr || parent->parent == nullptr)
            return nullptr;

        if (parent->isOnLeft())
            return parent->parent->right;

        return parent->parent->left;
    }

    // Verifica si es hijo izquierdo
    bool isOnLeft() {
        return this == parent->left;
    }

    // Retorna el hermano
    Node* sibling() {

        if (parent == nullptr)
            return nullptr;

        if (isOnLeft())
            return parent->right;

        return parent->left;
    }

    // Mueve nodo hacia abajo
    void moveDown(Node* nParent) {

        if (parent != nullptr) {

            if (isOnLeft())
                parent->left = nParent;
            else
                parent->right = nParent;
        }

        nParent->parent = parent;
        parent = nParent;
    }

    // Verifica si tiene hijo rojo
    bool hasRedChild() {

        return (left != nullptr && left->color == RED) ||
               (right != nullptr && right->color == RED);
    }
};

// Clase Árbol Red Black
class RBTree {

    Node* root;

    // Rotación izquierda
    void leftRotate(Node* x) {

        Node* nParent = x->right;

        if (x == root)
            root = nParent;

        x->moveDown(nParent);

        x->right = nParent->left;

        if (nParent->left != nullptr)
            nParent->left->parent = x;

        nParent->left = x;
    }

    // Rotación derecha
    void rightRotate(Node* x) {

        Node* nParent = x->left;

        if (x == root)
            root = nParent;

        x->moveDown(nParent);

        x->left = nParent->right;

        if (nParent->right != nullptr)
            nParent->right->parent = x;

        nParent->right = x;
    }

    // Intercambiar colores
    void swapColors(Node* x1, Node* x2) {

        COLOR temp = x1->color;
        x1->color = x2->color;
        x2->color = temp;
    }

    // Intercambiar valores
    void swapValues(Node* u, Node* v) {

        int temp = u->val;
        u->val = v->val;
        v->val = temp;
    }

    // Corregir conflicto rojo-rojo
    void fixRedRed(Node* x) {

        if (x == root) {

            x->color = BLACK;

            return;
        }

        Node* parent = x->parent;
        Node* grandparent = parent->parent;
        Node* uncle = x->uncle();

        if (parent->color != BLACK) {

            if (uncle != nullptr && uncle->color == RED) {

                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;

                fixRedRed(grandparent);
            }

            else {

                if (parent->isOnLeft()) {

                    if (x->isOnLeft()) {

                        // Caso LL
                        swapColors(parent, grandparent);
                    }

                    else {

                        // Caso LR
                        leftRotate(parent);

                        swapColors(x, grandparent);
                    }

                    rightRotate(grandparent);
                }

                else {

                    if (x->isOnLeft()) {

                        // Caso RL
                        rightRotate(parent);

                        swapColors(x, grandparent);
                    }

                    else {

                        // Caso RR
                        swapColors(parent, grandparent);
                    }

                    leftRotate(grandparent);
                }
            }
        }
    }

    // Buscar sucesor
    Node* successor(Node* x) {

        Node* temp = x;

        while (temp->left != nullptr)
            temp = temp->left;

        return temp;
    }

    // Reemplazo BST
    Node* BSTreplace(Node* x) {

        // Dos hijos
        if (x->left != nullptr && x->right != nullptr)
            return successor(x->right);

        // Hoja
        if (x->left == nullptr && x->right == nullptr)
            return nullptr;

        // Un hijo
        if (x->left != nullptr)
            return x->left;

        return x->right;
    }

    // Corregir doble negro
    void fixDoubleBlack(Node* x) {

        if (x == root)
            return;

        Node* sibling = x->sibling();
        Node* parent = x->parent;

        if (sibling == nullptr) {

            fixDoubleBlack(parent);
        }

        else {

            if (sibling->color == RED) {

                parent->color = RED;
                sibling->color = BLACK;

                if (sibling->isOnLeft())
                    rightRotate(parent);
                else
                    leftRotate(parent);

                fixDoubleBlack(x);
            }

            else {

                if (sibling->hasRedChild()) {

                    // Izquierda izquierda
                    if (sibling->left != nullptr &&
                        sibling->left->color == RED) {

                        if (sibling->isOnLeft()) {

                            sibling->left->color = sibling->color;
                            sibling->color = parent->color;

                            rightRotate(parent);
                        }

                        else {

                            sibling->left->color = parent->color;

                            rightRotate(sibling);
                            leftRotate(parent);
                        }
                    }

                    else {

                        // Derecha derecha
                        if (sibling->isOnLeft()) {

                            sibling->right->color = parent->color;

                            leftRotate(sibling);
                            rightRotate(parent);
                        }

                        else {

                            sibling->right->color = sibling->color;
                            sibling->color = parent->color;

                            leftRotate(parent);
                        }
                    }

                    parent->color = BLACK;
                }

                else {

                    sibling->color = RED;

                    if (parent->color == BLACK)
                        fixDoubleBlack(parent);
                    else
                        parent->color = BLACK;
                }
            }
        }
    }

    // Eliminar nodo
    void deleteNode(Node* v) {

        Node* u = BSTreplace(v);

        bool uvBlack =
            ((u == nullptr || u->color == BLACK) &&
             (v->color == BLACK));

        Node* parent = v->parent;

        // Caso hoja
        if (u == nullptr) {

            if (v == root) {

                root = nullptr;
            }

            else {

                if (uvBlack)
                    fixDoubleBlack(v);

                else if (v->sibling() != nullptr)
                    v->sibling()->color = RED;

                if (v->isOnLeft())
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            }

            delete v;

            return;
        }

        // Nodo con un hijo
        if (v->left == nullptr || v->right == nullptr) {

            if (v == root) {

                v->val = u->val;

                v->left = v->right = nullptr;

                delete u;
            }

            else {

                if (v->isOnLeft())
                    parent->left = u;
                else
                    parent->right = u;

                delete v;

                u->parent = parent;

                if (uvBlack)
                    fixDoubleBlack(u);
                else
                    u->color = BLACK;
            }

            return;
        }

        // Nodo con dos hijos
        swapValues(u, v);

        deleteNode(u);
    }

    // Recorrido inorder
    void inorder(Node* x) {

        if (x == nullptr)
            return;

        inorder(x->left);

        cout << x->val << " ";

        inorder(x->right);
    }

    // Recorrido por niveles
    void levelOrder(Node* x) {

        if (x == nullptr)
            return;

        queue<Node*> q;

        q.push(x);

        while (!q.empty()) {

            Node* curr = q.front();

            q.pop();

            cout << curr->val << " ";

            if (curr->left != nullptr)
                q.push(curr->left);

            if (curr->right != nullptr)
                q.push(curr->right);
        }
    }

    // Liberar memoria
    void destroyTree(Node* node) {

        if (node == nullptr)
            return;

        destroyTree(node->left);
        destroyTree(node->right);

        delete node;
    }

public:

    // Constructor
    RBTree() {
        root = nullptr;
    }

    // Destructor
    ~RBTree() {
        destroyTree(root);
    }

    // Buscar nodo
    Node* search(int n) {

        Node* temp = root;

        while (temp != nullptr) {

            if (n < temp->val) {

                if (temp->left == nullptr)
                    break;

                temp = temp->left;
            }

            else if (n == temp->val) {

                break;
            }

            else {

                if (temp->right == nullptr)
                    break;

                temp = temp->right;
            }
        }

        return temp;
    }

    // Insertar nodo
    void insert(int n) {

        Node* newNode = new Node(n);

        if (root == nullptr) {

            newNode->color = BLACK;

            root = newNode;
        }

        else {

            Node* temp = search(n);

            if (temp->val == n) {

                delete newNode;

                return;
            }

            newNode->parent = temp;

            if (n < temp->val)
                temp->left = newNode;
            else
                temp->right = newNode;

            fixRedRed(newNode);
        }
    }

    // Eliminar valor
    void deleteByVal(int n) {

        if (root == nullptr)
            return;

        Node* v = search(n);

        if (v->val != n) {

            cout << "No se encontro nodo con valor: "
                 << n << endl;

            return;
        }

        deleteNode(v);
    }

    // Mostrar inorder
    void printInOrder() {

        cout << "Inorder:" << endl;

        if (root == nullptr)
            cout << "Arbol vacio" << endl;
        else
            inorder(root);

        cout << endl;
    }

    // Mostrar level order
    void printLevelOrder() {

        cout << "Nivel en orden:" << endl;

        if (root == nullptr)
            cout << "Arbol vacio" << endl;
        else
            levelOrder(root);

        cout << endl;
    }
};

// Función principal
int main() {

    RBTree tree;

    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);
    tree.insert(2);
    tree.insert(6);
    tree.insert(13);

    tree.printInOrder();
    tree.printLevelOrder();

    cout << "\nBorrando 18, 11, 3, 10, 22\n" << endl;

    tree.deleteByVal(18);
    tree.deleteByVal(11);
    tree.deleteByVal(3);
    tree.deleteByVal(10);
    tree.deleteByVal(22);

    tree.printInOrder();
    tree.printLevelOrder();

    return 0;
}