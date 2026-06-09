#include <iostream>
using namespace std;

class BTree {
private:
    int T; // grado mínimo
    class Node {
    public:
        int n;          // número de claves
        int* key;       // arreglo de claves
        Node** child;   // arreglo de hijos
        bool leaf;      // indica si es hoja

        Node(int T) {
            key = new int[2 * T - 1];
            child = new Node*[2 * T];
            leaf = true;
            n = 0;
        }

        int Find(int k) {
            for (int i = 0; i < n; i++) {
                if (key[i] == k) {
                    return i;
                }
            }
            return -1;
        }
    };

    Node* root;

    // Dividir nodo
    void split(Node* x, int pos, Node* y) {
        Node* z = new Node(T);
        z->leaf = y->leaf;
        z->n = T - 1;
        // Copiar claves
        for (int j = 0; j < T - 1; j++) {
            z->key[j] = y->key[j + T];
        }
        // Copiar hijos
        if (!y->leaf) {
            for (int j = 0; j < T; j++) {
                z->child[j] = y->child[j + T];
            }
        }
        y->n = T - 1;
        // Mover hijos de x
        for (int j = x->n; j >= pos + 1; j--) {
            x->child[j + 1] = x->child[j];
        }
        x->child[pos + 1] = z;
        // Mover claves de x
        for (int j = x->n - 1; j >= pos; j--) {
            x->key[j + 1] = x->key[j];
        }
        x->key[pos] = y->key[T - 1];
        x->n = x->n + 1;
    }

    // Insertar en nodo no lleno
    void _insert(Node* x, int k) {
        if (x->leaf) {
            int i;

            for (i = x->n - 1; i >= 0 && k < x->key[i]; i--) {
                x->key[i + 1] = x->key[i];
            }


            x->key[i + 1] = k;
            x->n = x->n + 1;
        }
        else {
            int i;

            for (i = x->n - 1; i >= 0 && k < x->key[i]; i--);

            i++;

            Node* tmp = x->child[i];

            if (tmp->n == 2 * T - 1) {
                split(x, i, tmp);
                if (k > x->key[i]) {
                    i++;
                }
            }
            _insert(x->child[i], k);
        }
    }

    // Mostrar árbol
    void display(Node* x) {
        if (x == nullptr)
            return;

        for (int i = 0; i < x->n; i++) {
            cout << x->key[i] << " ";
        }

        if (!x->leaf) {
            for (int i = 0; i < x->n + 1; i++) {
                display(x->child[i]);
            }
        }
    }

public:
    BTree(int t) {
        T = t;
        root = new Node(T);
    }

    // Insertar clave
    void insert(int key) {
        Node* r = root;

        if (r->n == 2 * T - 1) {
            Node* s = new Node(T);

            root = s;
            s->leaf = false;
            s->n = 0;
            s->child[0] = r;

            split(s, 0, r);
            _insert(s, key);
        }
        else {
            _insert(r, key);
        }
    }

    void display() {
        display(root);
    }
};

int main() {
    BTree b(2);

    b.insert(5);
    b.insert(6);
    b.insert(7);
    b.insert(8);
    b.insert(12);
    b.insert(13);
    b.insert(14);

    b.display();
    return 0;
}