#include <iostream>
#include <vector>
using namespace std;

// Agrega una arista al grafo no dirigido
void addEdge(vector<vector<int>>& mat, int i, int j) {
    mat[i][j] = 1;
    mat[j][i] = 1; // Grafo no dirigido
}
// Muestra la matriz de adyacencia
void displayMatrix(const vector<vector<int>>& mat) {
    for (const auto& fila : mat) {
        for (int valor : fila) {
            cout << valor << " ";
        }
        cout << endl;
    }
}
int main() {
    // Crear un grafo con 4 vértices y sin aristas
    int V = 4;

    vector<vector<int>> mat(V, vector<int>(V, 0));

    // Agregar aristas
    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);

    cout << "Representacion de la matriz de adyacencia" << endl;

    displayMatrix(mat);

    return 0;
}
