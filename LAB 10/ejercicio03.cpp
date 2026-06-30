#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

// Clase Grafo usando templates (equivalente a los genéricos de Java)
template <typename T>
class Graph {
private:
    // Mapa para almacenar las listas de adyacencia
    unordered_map<T, list<T>> mapa;
public:
    // Agregar vértice
    void addVertex(T s) {
        mapa[s] = list<T>();
    }
    // Agregar arista
    void addEdge(T source, T destination, bool bidirectional) {
        if (mapa.find(source) == mapa.end())
            addVertex(source);

        if (mapa.find(destination) == mapa.end())
            addVertex(destination);

        mapa[source].push_back(destination);

        if (bidirectional) {
            mapa[destination].push_back(source);
        }
    }
    // Número de vértices
    void getVertexCount() {
        cout << "El grafo tiene "
             << mapa.size()
             << " vertices." << endl;
    }
    // Número de aristas
    void getEdgesCount(bool bidirectional) {
        int count = 0;

        for (auto const& v : mapa) {
            count += v.second.size();
        }

        if (bidirectional) {
            count /= 2;
        }
        cout << "El grafo tiene "
             << count
             << " aristas." << endl;
    }
    // Verificar si existe un vértice
    void hasVertex(T s) {
        if (mapa.find(s) != mapa.end()) {
            cout << "El grafo contiene "
                 << s
                 << " como un vertice." << endl;
        }
        else {
            cout << "El grafo no contiene "
                 << s
                 << " como un vertice." << endl;
        }
    }
    // Verificar si existe una arista
    void hasEdge(T s, T d) {
        if (mapa.find(s) != mapa.end()) {
            for (T vecino : mapa[s]) {
                if (vecino == d) {
                    cout << "El grafo tiene una arista entre "
                         << s << " y " << d << "." << endl;
                    return;
                }
            }
        }
        cout << "El grafo no tiene una arista entre "
             << s << " y " << d << "." << endl;
    }
    // Mostrar vecinos de un vértice
    void neighbours(T s) {
        if (mapa.find(s) == mapa.end())
            return;
        cout << "Los vecinos de " << s << " son: ";

        for (T vecino : mapa[s]) {
            cout << vecino << " ";
        }

        cout << endl;
    }
    // Imprimir lista de adyacencia
    void printGraph() {
        for (auto const& v : mapa) {
            cout << v.first << ": ";

            for (T vecino : v.second) {
                cout << vecino << " ";
            }

            cout << endl;
        }
    }
};
// Programa principal
int main() {
    Graph<int> g;

    // Agregar aristas
    g.addEdge(0, 1, true);
    g.addEdge(0, 4, true);
    g.addEdge(1, 2, true);
    g.addEdge(1, 3, true);
    g.addEdge(1, 4, true);
    g.addEdge(2, 3, true);
    g.addEdge(3, 4, true);

    // Mostrar el grafo
    cout << "Grafo:" << endl;
    g.printGraph();
    cout << endl;

    // Número de vértices
    g.getVertexCount();
    // Número de aristas
    g.getEdgesCount(true);
    // Verificar arista
    g.hasEdge(3, 4);
    // Verificar vértice
    g.hasVertex(5);
    // Mostrar vecinos
    g.neighbours(1);

    return 0;
}
