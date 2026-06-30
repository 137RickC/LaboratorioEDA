#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int,int>>> adj;

public:
    Graph(int vertices){
        V=vertices;
        adj.resize(V);
    }
    void addEdge(int u,int v,int peso){

        adj[u].push_back({v,peso});
        adj[v].push_back({u,peso});
    }
    void dijkstra(int origen){

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        vector<int> dist(V,INT_MAX);

        dist[origen]=0;

        pq.push({0,origen});

        while(!pq.empty()){

            int distancia=pq.top().first;
            int u=pq.top().second;
            pq.pop();

            if(distancia>dist[u])
                continue;

            for(auto vecino:adj[u]){

                int v=vecino.first;
                int peso=vecino.second;

                if(dist[v]>dist[u]+peso){

                    dist[v]=dist[u]+peso;
                    pq.push({dist[v],v});

                }
            }
        }

        cout<<"Distancias minimas desde el vertice "<<origen<<endl;

        for(int i=0;i<V;i++){
            cout<<"Vertice "<<i<<" -> "<<dist[i]<<endl;

        }

    }

};

int main(){
    Graph g(5);

    g.addEdge(0,1,10);
    g.addEdge(0,4,5);
    g.addEdge(1,2,1);
    g.addEdge(1,4,2);
    g.addEdge(2,3,4);
    g.addEdge(3,0,7);
    g.addEdge(3,2,6);
    g.addEdge(4,1,3);
    g.addEdge(4,2,9);
    g.addEdge(4,3,2);

    g.dijkstra(0);

    return 0;

}