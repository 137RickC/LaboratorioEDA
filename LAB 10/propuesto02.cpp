#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;
public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void BFS(int inicio) {

        vector<bool> visited(V,false);
        queue<int> q;

        visited[inicio]=true;
        q.push(inicio);

        cout << "Recorrido BFS: ";

        while(!q.empty()){

            int v=q.front();
            q.pop();

            cout << v << " ";

            for(int vecino:adj[v]){

                if(!visited[vecino]){
                    visited[vecino]=true;
                    q.push(vecino);
                }
            }
        }

        cout << endl;
    }
};
int main(){
    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);

    cout << "Grafo de 6 vertices" << endl;

    g.BFS(0);

    cout << endl;

    cout << "Comparacion:" << endl;
    cout << "DFS visita primero toda una rama antes de regresar." << endl;
    cout << "BFS visita primero todos los vecinos del nivel actual." << endl;

    return 0;
}