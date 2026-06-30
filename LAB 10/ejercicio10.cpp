#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Agregar arista en grafo dirigido
void addEdge(vector<list<int>>& adj, int u, int v){
    // Solo unidireccional
    adj[u].push_back(v);
}
// Imprimir lista de adyacencia (solo vértices con vecinos)
void printAdjacencyList(const vector<list<int>>& adj){
    for (int i = 0; i < adj.size(); i++) {
        // Solo imprimir si tiene conexiones
        if (!adj[i].empty()) {
            cout << i << " -> ";

            for (int v : adj[i]) {
                cout << v << " ";
            }

            cout << endl;
        }
    }
}

int main()
{
    int V = 5;
    // Crear lista de adyacencia
    vector<list<int>> adj(V);
    // Agregar aristas dirigidas
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    // Imprimir grafo
    printAdjacencyList(adj);

    return 0;
}
