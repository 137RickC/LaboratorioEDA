#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>> adj;
    int V;

public:
    // Constructor
    Graph(int v) {
        V = v;
        adj.resize(V);
        // En C++ no necesitas crear manualmente cada lista
        // vector ya inicializa automáticamente los sub-vectores
    }
    // Agregar arista (grafo no dirigido)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Imprimir lista de adyacencia
    void printAdjacencyList() {
        for (int i = 0; i < adj.size(); i++) {
            cout << "Lista de adyacencia " << i << endl;

            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j] << " ";
            }

            cout << endl;
        }
    }
};
int main() {
    // Creando un grafo con 5 vértices
    int V = 5;
    Graph g(V);
    // Añadiendo aristas
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // Mostrar grafo
    g.printAdjacencyList();

    return 0;
}
