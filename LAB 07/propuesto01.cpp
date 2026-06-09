#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
// Clase Nodo (Node)
class Node {
public:
    int order;
    std::vector<std::string> values;
    std::vector<std::vector<Node*>> keys; // Vector de vectores de punteros
    Node* nextKey;
    Node* parent;
    bool isLeaf;

    // Constructor de nodos
    Node(int order) {
        this->order = order;
        this->nextKey = nullptr;
        this->parent = nullptr;
        this->isLeaf = false;
    }

    // Destructor para evitar fugas de memoria
    ~Node() {
        // Solo eliminamos de forma jerárquica si no es hoja para evitar doble delete,
        // ya que el código del main inserta nodos temporales como valores.
        if (!isLeaf) {
            for (auto& vec : keys) {
                for (Node* child : vec) {
                    delete child;
                }
            }
        }
    }

    // Insertar en la hoja
    void insertAtLeaf(std::string value, Node* key) {
        if (!this->values.empty()) {
            for (size_t i = 0; i < this->values.size(); i++) {
                if (value == this->values[i]) {
                    this->keys[i].push_back(key);
                    break;
                } else if (value < this->values[i]) {
                    this->values.insert(this->values.begin() + i, value);
                    this->keys.insert(this->keys.begin() + i, std::vector<Node*>());
                    this->keys[i].push_back(key);
                    break;
                } else if (i + 1 == this->values.size()) {
                    this->values.push_back(value);
                    this->keys.push_back(std::vector<Node*>());
                    this->keys[i + 1].push_back(key);
                    break;
                }
            }
        } else {
            this->values.push_back(value);
            this->keys.push_back(std::vector<Node*>());
            this->keys[0].push_back(key);
        }
    }
};

// Clase Árbol B+ (BplusTree)
class BplusTree {
public:
    Node* root;
    // Constructor
    BplusTree(int order) {
        this->root = new Node(order);
        this->root->isLeaf = true;
    }
    // Destructor del árbol
    ~BplusTree() {
        delete root;
    }
    // Operación de búsqueda de nodo hoja para insertar
    Node* search(std::string value) {
        Node* currentNode = this->root;
        while (!currentNode->isLeaf) {
            for (size_t i = 0; i < currentNode->values.size(); i++) {
                if (value == currentNode->values[i]) {
                    currentNode = currentNode->keys[i + 1][0];
                    break;
                } else if (value < currentNode->values[i]) {
                    currentNode = currentNode->keys[i][0];
                    break;
                } else if (i + 1 == currentNode->values.size()) {
                    currentNode = currentNode->keys[i + 1][0];
                    break;
                }
            }
        }
        return currentNode;
    }

    // Operación insertar
    void insert(std::string value, Node* key) {
        Node* oldNode = this->search(value);
        oldNode->insertAtLeaf(value, key);

        if (oldNode->values.size() == static_cast<size_t>(oldNode->order)) {
            Node* newNode = new Node(oldNode->order);
            newNode->isLeaf = true;
            newNode->parent = oldNode->parent;
            
            int mid = static_cast<int>(std::ceil(oldNode->order / 2.0)) - 1;

            // Separar valores y llaves (subList equivalencias usando constructores de rango de vectores)
            newNode->values = std::vector<std::string>(oldNode->values.begin() + mid + 1, oldNode->values.end());
            newNode->keys = std::vector<std::vector<Node*>>(oldNode->keys.begin() + mid + 1, oldNode->keys.end());
            
            newNode->nextKey = oldNode->nextKey;

            oldNode->values = std::vector<std::string>(oldNode->values.begin(), oldNode->values.begin() + mid + 1);
            oldNode->keys = std::vector<std::vector<Node*>>(oldNode->keys.begin(), oldNode->keys.begin() + mid + 1);
            
            oldNode->nextKey = newNode;

            this->insertInParent(oldNode, newNode->values[0], newNode);
        }
    }


    // Encuentra si un valor y su nodo asociado existen
    bool find(std::string value, Node* key) {
        Node* leaf = this->search(value);
        for (size_t i = 0; i < leaf->values.size(); i++) {
            if (leaf->values[i] == value) {
                // Simulación de java.util.List.contains utilizando std::find de C++
                auto& vec = leaf->keys[i];
                // Nota: En la lógica original de tu Main de Java, comparas con una nueva instancia 'new Node(3)', 
                // lo que en C++ comparará direcciones de memoria diferentes. He replicado la lógica exacta.
                if (std::find(vec.begin(), vec.end(), key) != vec.end()) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }
    // Búsqueda por rango [inicio, fin]
    std::vector<std::string> rangeSearch(std::string inicio,
                                        std::string fin) {

        std::vector<std::string> resultado;

        // Buscar la hoja donde comienza el rango
        Node* hoja = this->search(inicio);

        while (hoja != nullptr) {

            for (size_t i = 0; i < hoja->values.size(); i++) {

                if (hoja->values[i] >= inicio &&
                    hoja->values[i] <= fin) {

                    resultado.push_back(hoja->values[i]);
                }

                // Si ya superamos el límite superior, terminamos
                if (hoja->values[i] > fin) {
                    return resultado;
                }
            }

            hoja = hoja->nextKey;
        }

        return resultado;
    }

    // Insertando en el padre
    void insertInParent(Node* n, std::string value, Node* ndash) {
        if (this->root == n) {
            Node* rootNode = new Node(n->order);
            rootNode->values.push_back(value);
            rootNode->keys.push_back(std::vector<Node*>());
            rootNode->keys.push_back(std::vector<Node*>());
            rootNode->keys[0].push_back(n);
            rootNode->keys[1].push_back(ndash);
            this->root = rootNode;
            n->parent = rootNode;
            ndash->parent = rootNode;
            return;
        }

        Node* parentNode = n->parent;
        for (size_t i = 0; i < parentNode->keys.size(); i++) {
            if (parentNode->keys[i][0] == n) {
                parentNode->values.insert(parentNode->values.begin() + i, value);
                parentNode->keys.insert(parentNode->keys.begin() + i + 1, std::vector<Node*>());
                parentNode->keys[i + 1].push_back(ndash);

                if (parentNode->keys.size() > static_cast<size_t>(parentNode->order)) {
                    Node* parentdash = new Node(parentNode->order);
                    parentdash->parent = parentNode->parent;
                    
                    int mid = static_cast<int>(std::ceil(parentNode->order / 2.0)) - 1;

                    parentdash->values = std::vector<std::string>(parentNode->values.begin() + mid + 1, parentNode->values.end());
                    parentdash->keys = std::vector<std::vector<Node*>>(parentNode->keys.begin() + mid + 1, parentNode->keys.end());
                    
                    std::string value_ = parentNode->values[mid];

                    if (mid == 0) {
                        parentNode->values = std::vector<std::string>(parentNode->values.begin(), parentNode->values.begin() + mid + 1);
                    } else {
                        parentNode->values = std::vector<std::string>(parentNode->values.begin(), parentNode->values.begin() + mid);
                    }
                    parentNode->keys = std::vector<std::vector<Node*>>(parentNode->keys.begin(), parentNode->keys.begin() + mid + 1);

                    for (size_t j = 0; j < parentNode->keys.size(); j++) {
                        parentNode->keys[j][0]->parent = parentNode;
                    }
                    for (size_t j = 0; j < parentdash->keys.size(); j++) {
                        parentdash->keys[j][0]->parent = parentdash;
                    }
                    this->insertInParent(parentNode, value_, parentdash);
                }
                break;
            }
        }
    }
};

// Función auxiliar para imprimir los valores de un vector
void printValues(const std::vector<std::string>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i + 1 < vec.size()) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// Dibujando el árbol (Función global adaptada de Java)
void printTree(BplusTree* tree) {
    std::vector<Node*> lst;
    lst.push_back(tree->root);
    std::vector<int> level;
    level.push_back(0);
    Node* leaf = nullptr;
    int flag = 0;
    int lev_leaf = 0;

    while (!lst.empty()) {
        Node* x = lst[0];
        lst.erase(lst.begin());
        int lev = level[0];
        level.erase(level.begin());


        if (!x->isLeaf) {
            for (size_t i = 0; i < x->keys.size(); i++) {
                printValues(x->keys[i][0]->values);
                // Para emular el recorrido por niveles en anchura agregamos a la cola:
                lst.push_back(x->keys[i][0]);
                level.push_back(lev + 1);
            }
        } else {
            // Nota: En la lógica original de tu código Java, se intenta acceder a x.keys.get(i).get(0).values 
            // en las hojas. Sin embargo, en las hojas de un Árbol B+, "keys" suele guardar punteros a datos de registros, 
            // no necesariamente subnodos con el campo 'values' poblado. Se mantiene fiel a tu lógica original de impresión.
            for (size_t i = 0; i < x->keys.size(); i++) {
                if (!x->keys[i].empty() && x->keys[i][0] != nullptr) {
                    printValues(x->keys[i][0]->values);
                }
            }
            if (flag == 0) {
                lev_leaf = lev;
                leaf = x;
                flag = 1;
            }
        }
    }
}

// Código Driver (main)
int main() {

    BplusTree* bplusTree =
        new BplusTree(3);

    bplusTree->insert("5", new Node(3));
    bplusTree->insert("15", new Node(3));
    bplusTree->insert("25", new Node(3));
    bplusTree->insert("35", new Node(3));
    bplusTree->insert("45", new Node(3));
    bplusTree->insert("55", new Node(3));
    bplusTree->insert("65", new Node(3));

    std::vector<std::string> rango =
        bplusTree->rangeSearch("15", "55");

    std::cout
        << "Valores entre 15 y 55:\n";

    for (const auto& valor : rango) {
        std::cout << valor << " ";
    }

    std::cout << std::endl;

    delete bplusTree;

    return 0;
}