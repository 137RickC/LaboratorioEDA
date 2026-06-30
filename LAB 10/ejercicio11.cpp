#include <iostream>
#include <vector>
using namespace std;

// Agregar arista en grafo no dirigido
void addEdge(vector<vector<int>>& adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Imprimir lista de adyacencia
void printAdjacencyList(const vector<vector<int>>& adj)
{
    for (int i = 0; i < adj.size(); i++) {
        cout << "Lista de Adyacencia " << i << endl;

        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }
}

int main(){
    // Creando un grafo con 5 vértices
    int V = 5;
    vector<vector<int>> adj(V);
    // Añadiendo aristas
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    // Imprimir grafo
    printAdjacencyList(adj);

    return 0;
}
