#include <iostream>
#include <vector>
using namespace std;

// Clase para representar un grafo dirigido
class DirectedGraph {
private:
    // Matriz de adyacencia
    vector<vector<int>> adjacencyMatrix;
    // Número de vértices
    int numVertices;
public:
    // Constructor
    DirectedGraph(int numVertices) {
        this->numVertices = numVertices;

        adjacencyMatrix.resize(
            numVertices,
            vector<int>(numVertices, 0)
        );
    }
    // Agregar una arista dirigida
    void addEdge(int source, int destination) {
        adjacencyMatrix[source][destination] = 1;
    }
    // Eliminar una arista dirigida
    void removeEdge(int source, int destination) {
        adjacencyMatrix[source][destination] = 0;
    }
    // Verificar si existe una arista
    bool hasEdge(int source, int destination) {
        return adjacencyMatrix[source][destination] == 1;
    }
    // Mostrar la matriz de adyacencia
    void printGraph() {
        cout << "Representacion del grafo (Matriz de adyacencia):"
             << endl;

        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }

            cout << endl;
        }
    }
};

// Programa principal
int main() {
    // Crear un grafo dirigido con 4 vértices
    DirectedGraph graph(4);

    // Agregar aristas
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);

    // Mostrar el grafo
    graph.printGraph();

    // Verificar aristas
    cout << "\nComprueba si hay una arista "
         << "del vertice 2 al 0: "
         << graph.hasEdge(2, 0)
         << endl;

    cout << "Comprueba si hay una arista "
         << "del vertice 3 al 1: "
         << graph.hasEdge(3, 1)
         << endl;

    // Eliminar una arista
    graph.removeEdge(2, 0);

    cout << "\nDespues de remover la arista "
         << "del vertice 2 al 0:"
         << endl;

    graph.printGraph();

    return 0;
}
