#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
// Clase Nodo (Node)
class Node {
public:
    std::vector<int> keys;
    std::vector<Node*> values; // En nodos internos son hijos, en hojas pueden ser datos (aquí punteros)
    bool leaf;
    Node* next;

    // Constructor de nodos
    Node(bool leaf) {
        this->leaf = leaf;
        this->next = nullptr;
    }

    // Destructor recursivo para liberar la memoria correctamente
    ~Node() {
        if (!leaf) {
            for (Node* child : values) {
                delete child;
            }
        }
    }
};
// Clase Árbol B+ (BPlusTree)
class BPlusTree {
private:
    Node* root;
    int degree;
    // Métodos privados de soporte para inserción, borrado y rebalanceo
    void insertNonFull(Node* curr, int key) {
        int i = 0;
        while (i < curr->keys.size()) {
            if (key < curr->keys[i]) {
                break;
            }
            i += 1;
        }
        if (curr->leaf) {
            curr->keys.insert(curr->keys.begin() + i, key);
        } else {
            if (curr->values[i]->keys.size() == 2 * this->degree) {
                this->split(curr, i, curr->values[i]);
                if (key > curr->keys[i]) {
                    i += 1;
                }
            }
            this->insertNonFull(curr->values[i], key);
        }
    }
    void split(Node* parent, int index, Node* node) {
        Node* new_node = new Node(node->leaf);
        
        // Insertar el nuevo nodo en el vector de valores del padre
        parent->values.insert(parent->values.begin() + index + 1, new_node);
        // Promocionar la clave intermedia al padre
        parent->keys.insert(parent->keys.begin() + index, node->keys[this->degree - 1]);

        // Mover las claves correspondientes al nuevo nodo
        new_node->keys.insert(new_node->keys.end(), node->keys.begin() + this->degree, node->keys.end());
        node->keys.erase(node->keys.begin() + this->degree - 1, node->keys.end());

        if (!node->leaf) {
            // Si no es hoja, también movemos los hijos (values)
            new_node->values.insert(new_node->values.end(), node->values.begin() + this->degree, node->values.end());
            node->values.erase(node->values.begin() + this->degree, node->values.end());
        }
    }

    void stealFromLeft(Node* parent, int i) {
        Node* node = parent->values[i];
        Node* leftSibling = parent->values[i - 1];
        
        node->keys.insert(node->keys.begin(), parent->keys[i - 1]);
        parent->keys[i - 1] = leftSibling->keys.back();
        leftSibling->keys.pop_back();
        
        if (!node->leaf) {
            node->values.insert(node->values.begin(), leftSibling->values.back());
            leftSibling->values.pop_back();
        }
    }

    void stealFromRight(Node* parent, int i) {
        Node* node = parent->values[i];
        Node* rightSibling = parent->values[i + 1];
        
        node->keys.push_back(parent->keys[i]);
        parent->keys[i] = rightSibling->keys.front();
        rightSibling->keys.erase(rightSibling->keys.begin());
        
        if (!node->leaf) {
            node->values.push_back(rightSibling->values.front());
            rightSibling->values.erase(rightSibling->values.begin());
        }
    }

    void deleteFromLeaf(int key, Node* leaf) {
        // Eliminar la clave por valor
        auto it = std::find(leaf->keys.begin(), leaf->keys.end(), key);
        if (it != leaf->keys.end()) {
            leaf->keys.erase(it);
        }


        if (leaf == this->root || leaf->keys.size() >= std::floor(this->degree / 2.0)) {
            return;
        }

        Node* parent = this->findParent(leaf);
        if (parent == nullptr) return;

        // Buscar el índice del nodo actual dentro de los hijos del padre
        auto v_it = std::find(parent->values.begin(), parent->values.end(), leaf);
        int i = std::distance(parent->values.begin(), v_it);


        if (i > 0 && parent->values[i - 1]->keys.size() > std::floor(this->degree / 2.0)) {
            this->rotateRight(parent, i);
        } else if (i < parent->keys.size() && parent->values[i + 1]->keys.size() > std::floor(this->degree / 2.0)) {
            this->rotateLeft(parent, i);
        } else {
            if (i == parent->keys.size()) {
                i -= 1;
            }
            this->merge(parent, i, parent->values[i], parent->values[i + 1]);
        }
    }

    int getMinKey(Node* node) {
        while (!node->leaf) {
            node = node->values.front();
        }
        return node->keys.front();
    }
    int getMaxKey(Node* node) {
        while (!node->leaf) {
            node = node->values.back();
        }
        return node->keys.back();
    }

    Node* findParent(Node* child) {
        Node* curr = this->root;
        while (!curr->leaf) {
            int i = 0;
            while (i < curr->values.size()) {
                if (child == curr->values[i]) {
                    return curr;
                } else if (!curr->values[i]->keys.empty() && child->keys[0] < curr->values[i]->keys[0]) {
                    break;
                }
                i += 1;
            }
            curr = curr->values[i];
        }
        return nullptr;
    }

    void merge(Node* parent, int i, Node* pred, Node* succ) {
        pred->keys.insert(pred->keys.end(), succ->keys.begin(), succ->keys.end());
        pred->values.insert(pred->values.end(), succ->values.begin(), succ->values.end());
        
        parent->values.erase(parent->values.begin() + i + 1);
        parent->keys.erase(parent->keys.begin() + i);

        // MUY IMPORTANTE: En C++ debemos liberar la memoria del nodo que se fusionó y quedó vacío (succ)
        succ->values.clear(); // Limpiamos para que su destructor no borre en cascada a los hijos ahora de 'pred'
        delete succ;

        if (parent == this->root && parent->keys.size() == 0) {
            this->root = pred;
            // El padre antiguo quedó vacío y deja de ser la raíz, se debe liberar en un escenario real, 
            // pero para mantener consistencia con el flujo del algoritmo procedemos con cuidado.
        }
    }

    void rotateRight(Node* parent, int i) {
        Node* node = parent->values[i];
        Node* prev = parent->values[i - 1];
        node->keys.insert(node->keys.begin(), parent->keys[i - 1]);
        parent->keys[i - 1] = prev->keys.back();
        prev->keys.pop_back();
        if (!node->leaf) {
            node->values.insert(node->values.begin(), prev->values.back());
            prev->values.pop_back();
        }
    }

    void rotateLeft(Node* parent, int i) {
        Node* node = parent->values[i];
        Node* next = parent->values[i + 1];
        node->keys.push_back(parent->keys[i]);
        parent->keys[i] = next->keys.front();
        next->keys.erase(next->keys.begin());
        if (!node->leaf) {
            node->values.push_back(next->values.front());
            next->values.erase(next->values.begin());
        }
    }

public:
    // Constructor del Árbol
    BPlusTree(int degree) {
        this->root = new Node(true);
        this->degree = degree;
    }

    // Destructor del Árbol
    ~BPlusTree() {
        delete root;
    }

    bool search(int key) {
        Node* curr = this->root;
        while (!curr->leaf) {
            int i = 0;
            while (i < curr->keys.size()) {
                if (key < curr->keys[i]) {
                    break;
                }
                i += 1;
            }
            curr = curr->values[i];
        }
        int i = 0;
        while (i < curr->keys.size()) {
            if (curr->keys[i] == key) {
                return true;
            }
            i += 1;
        }
        return false;
    }

    void insert(int key) {
        Node* curr = this->root;
        if (curr->keys.size() == 2 * this->degree) {
            Node* newRoot = new Node(false);
            this->root = newRoot;
            newRoot->values.push_back(curr);
            this->split(newRoot, 0, curr);
            this->insertNonFull(newRoot, key);
        } else {
            this->insertNonFull(curr, key);
        }
    }

    void deleteKey(int key) {
        Node* curr = this->root;
        bool found = false;
        int i = 0;
        while (i < curr->keys.size()) {
            if (key == curr->keys[i]) {
                found = true;
                break;
            } else if (key < curr->keys[i]) {
                break;
            }
            i += 1;
        }
        
        if (found) {
            if (curr->leaf) {
                curr->keys.erase(curr->keys.begin() + i);
            } else {
                Node* pred = curr->values[i];
                if (pred->keys.size() >= this->degree) {
                    int predKey = this->getMaxKey(pred);
                    curr->keys[i] = predKey;
                    this->deleteFromLeaf(predKey, pred);
                } else {
                    Node* succ = curr->values[i + 1];
                    if (succ->keys.size() >= this->degree) {
                        int succKey = this->getMinKey(succ);
                        curr->keys[i] = succKey;
                        this->deleteFromLeaf(succKey, succ);
                    } else {
                        this->merge(curr, i, pred, succ);
                        this->deleteFromLeaf(key, pred);
                    }
                }

                if (curr == this->root && curr->keys.size() == 0) {
                    this->root = curr->values[0];
                    // Nota: Aquí el nodo 'curr' original (antigua raíz) quedó huérfano de claves, 
                    // se borra su rastro interno para evitar fugas.
                    curr->values.clear();
                    delete curr;
                }
            }
        } else {
            if (curr->leaf) {
                return;
            } else {
                if (curr->values[i]->keys.size() < this->degree) {
                    if (i != 0 && curr->values[i - 1]->keys.size() >= this->degree) {
                        this->stealFromLeft(curr, i);
                    } else if (i != curr->keys.size() && curr->values[i + 1]->keys.size() >= this->degree) {
                        this->stealFromRight(curr, i);
                    } else {
                        if (i == curr->keys.size()) {
                            i -= 1;
                        }
                        this->merge(curr, i, curr->values[i], curr->values[i + 1]);
                    }
                }
                this->deleteKey(key);
            }
        }
    }

    void printTree() {
        std::vector<Node*> currLevel;
        currLevel.push_back(this->root);

        while (!currLevel.empty()) {
            std::vector<Node*> nextLevel;

            for (Node* node : currLevel) {
                std::cout << "[";
                for (size_t k = 0; k < node->keys.size(); ++k) {
                    std::cout << node->keys[k];
                    if (k + 1 < node->keys.size()) std::cout << ", ";
                }
                std::cout << "] ";

                if (!node->leaf) {
                    nextLevel.insert(nextLevel.end(), node->values.begin(), node->values.end());
                }
            }
            std::cout << std::endl;
            currLevel = nextLevel;
        }
    }
};

// Código Driver
int main() {
    // Crea un árbol B+ con grado 3
    BPlusTree tree(3);

    // Insertamos algunas claves
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);

    // Imprime el árbol
    std::cout << "--- Arbol Inicial ---" << std::endl;
    tree.printTree(); 

    // Elimina una clave
    std::cout << "\n--- Eliminando la clave 3 ---" << std::endl;
    tree.deleteKey(3);

    // Imprime el árbol nuevamente
    tree.printTree(); 
    return 0;
}
