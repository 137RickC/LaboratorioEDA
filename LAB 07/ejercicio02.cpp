#include <iostream>
#include <vector>
// Declaración estructurada de las clases
class BTreeNode {
public:
    std::vector<int> keys;
    int t;
    std::vector<BTreeNode*> C;
    int n;
    bool leaf;

    BTreeNode(int _t, bool _leaf) {
        t = _t;
        leaf = _leaf;
        // Se reserva el tamaño máximo posible para las llaves y los hijos
        keys.resize(2 * t - 1);
        C.resize(2 * t, nullptr);
        n = 0;
    }

    // Destructor para liberar de forma recursiva la memoria de los nodos hijos
    ~BTreeNode() {
        if (!leaf) {
            for (int i = 0; i <= n; i++) {
                delete C[i];
            }
        }
    }

    void traverse() {
        int i;
        for (i = 0; i < n; i++) {
            if (!leaf) {
                C[i]->traverse();
            }
            std::cout << " " << keys[i];
        }
        if (!leaf) {
            C[i]->traverse();
        }
    }

    BTreeNode* search(int k) {
        int i = 0;
        while (i < n && k > keys[i]) {
            i++;
        }
        if (i < n && k == keys[i]) {
            return this;
        }
        if (leaf) {
            return nullptr;
        }
        return C[i]->search(k);
    }

    void insertNonFull(int k) {
        int i = n - 1;
        if (leaf) {
            while (i >= 0 && keys[i] > k) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
            n++;
        } else {
            while (i >= 0 && keys[i] > k) {
                i--;
            }
            if (C[i + 1]->n == 2 * t - 1) {
                splitChild(i + 1, C[i + 1]);
                if (keys[i + 1] < k) {
                    i++;
                }
            }
            C[i + 1]->insertNonFull(k);
        }
    }

    void splitChild(int i, BTreeNode* y) {
        BTreeNode* z = new BTreeNode(y->t, y->leaf);
        z->n = t - 1;

        for (int j = 0; j < t - 1; j++) {
            z->keys[j] = y->keys[j + t];
        }

        if (!y->leaf) {
            for (int j = 0; j < t; j++) {
                z->C[j] = y->C[j + t];
            }
        }

        y->n = t - 1;

        for (int j = n; j >= i + 1; j--) {
            C[j + 1] = C[j];
        }

        C[i + 1] = z;

        for (int j = n - 1; j >= i; j--) {
            keys[j + 1] = keys[j];
        }

        keys[i] = y->keys[t - 1];
        n++;
    }
};

class BTree {
private:
    BTreeNode* root;
    int t;
public:
    BTree(int _t) {
        root = nullptr;
        t = _t;
    }

    // Destructor del árbol
    ~BTree() {
        delete root;
    }

    void traverse() {
        if (root != nullptr) {
            root->traverse();
        }
    }

    BTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }

    void insert(int k) {
        if (root == nullptr) {
            root = new BTreeNode(t, true);
            root->keys[0] = k;
            root->n = 1;
        } else {
            if (root->n == 2 * t - 1) {
                BTreeNode* s = new BTreeNode(t, false);
                s->C[0] = root;
                s->splitChild(0, root);

                int i = 0;
                if (s->keys[0] < k) {
                    i++;
                }
                s->C[i]->insertNonFull(k);
                root = s;
            } else {
                root->insertNonFull(k);
            }
        }
    }
};

int main() {
    BTree t(3);
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    std::cout << "Recorrido del árbol construido es";
    t.traverse();
    std::cout << std::endl;

    int key = 6;
    if (t.search(key) != nullptr) {
        std::cout << key << " | Presente" << std::endl;
    } else {
        std::cout << key << " | No Presente" << std::endl;
    }

    key = 15;
    if (t.search(key) != nullptr) {
        std::cout << key << " | Presente" << std::endl;
    } else {
        std::cout << key << " | No Presente" << std::endl;
    }

    return 0;
}
