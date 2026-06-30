#include <iostream>
#include <list>
using namespace std;

// Clase para representar un grafo no dirigido utilizando una lista de adyacencia
class Grafo {
private:
    int V; // Número de vértices
    list<int>* listaAdyacencia; // Lista de adyacencia
public:
    // Constructor para inicializar el grafo con un número dado de vértices
    Grafo(int v) {
        V = v;
        listaAdyacencia = new list<int>[V];
    }
    // Método para agregar una arista al grafo
    void agregarArista(int v, int w) {
        listaAdyacencia[v].push_back(w);
        listaAdyacencia[w].push_back(v); // Grafo no dirigido
    }
    // Método para imprimir el grafo
    void imprimirGrafo() {
        for (int i = 0; i < V; i++) {
            cout << "Lista de adyacencia del vertice " << i << endl;
            cout << "Vertice " << i;

            for (int nodoAdyacente : listaAdyacencia[i]) {
                cout << " -> " << nodoAdyacente;
            }

            cout << "\n" << endl;
        }
    }

    // Destructor para liberar memoria
    ~Grafo() {
        delete[] listaAdyacencia;
    }
};

int main() {
    Grafo grafo(5); // Crear un grafo con 5 vértices
    // Agregar aristas al grafo
    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 4);
    grafo.agregarArista(1, 2);
    grafo.agregarArista(1, 3);
    grafo.agregarArista(1, 4);
    grafo.agregarArista(2, 3);

    // Imprimir el grafo
    grafo.imprimirGrafo();

    return 0;
}
