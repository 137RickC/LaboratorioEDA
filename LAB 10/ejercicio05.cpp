#include <iostream>
#include <vector>
using namespace std;

// Método para agregar una arista entre dos vértices
void addEdge(vector<vector<int>>& adj, int i, int j) {
    adj[i].push_back(j);
    adj[j].push_back(i); // Grafo no dirigido
}

// Método para mostrar la lista de adyacencia
void displayAdjList(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": ";

        for (int vertice : adj[i]) {
            cout << vertice << " ";
        }
        cout << endl;
    }
}
// Programa principal
int main() {
    // Crear un grafo con 4 vértices y sin aristas
    int V = 4;

    vector<vector<int>> adj(V);
    // Agregar aristas
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    cout << "Representacion de lista de adyacencia:" << endl;

    displayAdjList(adj);

    return 0;
}
