#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int vecino : adj[v]) {
            if (!visited[vecino]) {
                DFSUtil(vecino, visited);
            }
        }
    }
public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void DFS(int inicio) {
        vector<bool> visited(V, false);

        cout << "Recorrido DFS: ";
        DFSUtil(inicio, visited);
        cout << endl;
    }
};

int main() {

    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);

    cout << "Grafo de 6 vertices" << endl;
    g.DFS(0);

    return 0;
}