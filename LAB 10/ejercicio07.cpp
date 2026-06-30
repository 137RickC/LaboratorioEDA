#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    // Matriz de adyacencia
    vector<vector<bool>> adjacencyMatrix;
    // Número de vértices
    int numVertices;
public:
    // Constructor
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjacencyMatrix.resize(
            numVertices,
            vector<bool>(numVertices, false)
        );
    }
    // Agregar una arista
    void addEdge(int i, int j) {
        adjacencyMatrix[i][j] = true;
        adjacencyMatrix[j][i] = true; // Grafo no dirigido
    }
    // Eliminar una arista
    void removeEdge(int i, int j) {
        adjacencyMatrix[i][j] = false;
        adjacencyMatrix[j][i] = false; // Grafo no dirigido
    }
    // Verificar si existe una arista
    bool hasEdge(int i, int j) {
        return adjacencyMatrix[i][j];
    }

    // Imprimir la matriz de adyacencia
    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {

                cout << (adjacencyMatrix[i][j] ? "1 " : "0 ");
            }
            cout << endl;
        }
    }
};
int main() {
    // Crear un grafo con 4 vértices
    Graph graph(4);

    // Agregar aristas
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);

    cout << "Representacion del grafo (Matriz de adyacencia):"
         << endl;

    graph.printGraph();

    // Verificar aristas
    cout << "\nComprobando si hay una arista entre "
         << "los vertices 0 y 1: "
         << graph.hasEdge(0, 1)
         << endl;

    cout << "Comprobando si hay una arista entre "
         << "los vertices 0 y 3: "
         << graph.hasEdge(0, 3)
         << endl;

    // Eliminar una arista
    graph.removeEdge(1, 2);

    cout << "\nDespues de remover la arista "
         << "entre los vertices 1 y 2:"
         << endl;

    graph.printGraph();

    return 0;
}
