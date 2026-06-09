#include <iostream>
#include <vector>
#include <string>

class BTreeNode {
private:
    std::vector<int> keys;         // Vector de claves
    int t;                         // Grado mínimo
    std::vector<BTreeNode*> C;     // Vector de punteros a hijos
    bool leaf;                     // Verdadero si es nodo hoja
public:
    // Constructor
    BTreeNode(int t, bool leaf) {
        this->t = t;
        this->leaf = leaf;
    }

    // Destructor para liberar la memoria de manera recursiva
    ~BTreeNode() {
        if (!leaf) {
            for (BTreeNode* child : C) {
                delete child;
            }
        }
    }

    // Recorre el nodo e imprime su contenido indentado con tabulaciones
    void traverse(int tab) {
        std::string s(tab, '\t'); // Crea un string con 'tab' número de tabulaciones
        for (size_t i = 0; i < keys.size(); i++) {
            // Si no es hoja, primero recorre el subárbol del hijo C[i]
            if (!leaf && i < C.size()) {
                C[i]->traverse(tab + 1);
            }
            std::cout << s << keys[i] << std::endl;
        }

        // Imprimir el subárbol enraizado con el último hijo
        if (!leaf && C.size() > keys.size()) {
            C[keys.size()]->traverse(tab + 1);
        }
    }

    // Devuelve verdadero si el nodo está lleno
    bool isFull() {
        return keys.size() == static_cast<size_t>(2 * t - 1);
    }

    // Crea una nueva raíz, estableciendo la raíz actual como su hijo
    BTreeNode* makeNewRoot(int val, BTreeNode* newEntry) {
        BTreeNode* root = new BTreeNode(t, false);
        root->keys.push_back(val);
        root->C.push_back(this);
        root->C.push_back(newEntry);
        return root;
    }

    // Función para dividir el nodo actual (solo nodos no hojas)
    void split(int& val, BTreeNode*& newEntry) {
        BTreeNode* newNode = new BTreeNode(t, false);

        // El elemento en la posición t se convierte en el padre
        val = this->keys[t];

        // Las últimas entradas (t-1) irán al nuevo nodo
        for (int i = t + 1; i < 2 * t; i++) {
            newNode->keys.push_back(this->keys[i]);
        }

        // Este nodo se queda con las primeras t entradas
        this->keys.erase(this->keys.begin() + t, this->keys.end());

        // Las últimas entradas de hijos irán al nuevo nodo
        for (int i = t + 1; i <= 2 * t; i++) {
            newNode->C.push_back(this->C[i]);
        }

        // Este nodo elimina las referencias de los hijos que se movieron
        this->C.erase(this->C.begin() + t + 1, this->C.end());
        this->C.push_back(newNode);
    }

    // Función para insertar una nueva clave en el nodo
    void insert(int newKey, int& val, BTreeNode*& newEntry) {
        if (!leaf) {
            size_t i = 0;
            // Encuentra la primera clave mayor que newKey
            while (i < keys.size() && newKey > keys[i]) {
                i++;
            }

            // Insertar recursivamente en el hijo correspondiente
            C[i]->insert(newKey, val, newEntry);

            // Si no se realizó ninguna división en el hijo, salimos
            if (newEntry == nullptr) return;

            if (keys.size() < static_cast<size_t>(2 * t - 1)) {
                // Este nodo tiene espacio. Insertamos la clave y el nuevo hijo
                keys.insert(keys.begin() + i, val);
                C.insert(C.begin() + i + 1, newEntry);
                newEntry = nullptr; // Ya se acomodó la división
            } else {
                // El nodo está lleno, insertamos temporalmente para luego dividir
                keys.insert(keys.begin() + i, val);
                C.insert(C.begin() + i + 1, newEntry);

                // El nodo actual tiene 2*t claves, se procede a dividir
                split(val, newEntry);
            }
        } else {
            // Si es nodo hoja, buscamos la posición correcta de inserción
            size_t i = 0;
            while (i < keys.size() && newKey > keys[i]) {
                i++;
            }
            keys.insert(keys.begin() + i, newKey);

            // Si al insertar la hoja se llenó por completo (2 * t claves)
            if (keys.size() == static_cast<size_t>(2 * t)) {
                BTreeNode* newLeaf = new BTreeNode(t, true);
                // La clave en la posición t subirá al padre
                val = this->keys[t];
                // Pasamos las últimas (t-1) claves al nuevo nodo hoja
                for (int j = t + 1; j < 2 * t; j++) {
                    newLeaf->keys.push_back(this->keys[j]);
                }
                // Conservamos solo las primeras t claves en este nodo
                this->keys.erase(this->keys.begin() + t, this->keys.end());
                newEntry = newLeaf;
            }
        }
    }
};

class BTree {
private:
    BTreeNode* root;
    int t;

public:
    // Constructor
    BTree(int t) {
        this->root = new BTreeNode(t, true);
        this->t = t;
    }
    // Destructor para limpiar la memoria desde la raíz
    ~BTree() {
        delete root;
    }
    // Función para insertar un nuevo valor en el árbol B
    void insert(int key) {
        BTreeNode* newEntry = nullptr;
        int val = 0;
        root->insert(key, val, newEntry);
        // Si newEntry no es nulo, significa que la raíz se dividió y necesitamos una nueva
        if (newEntry != nullptr) {
            root = root->makeNewRoot(val, newEntry);
        }
    }

    // Muestra el árbol
    void display() {
        root->traverse(0);
    }
};

// Código Driver (main)
int main() {
    BTree tree(3);

    std::cout << "Despues de insertar 1 y 2" << std::endl;
    tree.insert(1);
    tree.insert(2);
    tree.display();
    std::cout << "------------------------" << std::endl;

    std::cout << "Despues de insertar 5 y 6" << std::endl;
    tree.insert(5);
    tree.insert(6);
    tree.display();
    std::cout << "------------------------" << std::endl;

    std::cout << "Despues de insertar 3 y 4" << std::endl;
    tree.insert(3);
    tree.insert(4);
    tree.display();
    std::cout << "------------------------" << std::endl;

    return 0;
}
