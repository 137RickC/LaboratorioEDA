#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Agregar una arista al grafo no dirigido
void addEdge(vector<list<int>>& adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Mostrar la lista de adyacencia
void printAdjacencyList(const vector<list<int>>& adj){
    for (int i = 0; i < adj.size(); i++) {
        cout << i << " -> ";

        for (int v : adj[i]) {
            cout << v << " ";
        }

        cout << endl;
    }
}
int main(){
    // Número de vértices
    int V = 5;

    // Crear lista de adyacencia
    vector<list<int>> adj(V);
    // Insertar aristas
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    // Mostrar lista de adyacencia
    printAdjacencyList(adj);

    return 0;
}
