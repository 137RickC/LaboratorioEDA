#include <iostream>
#include <vector>
using namespace std;

class MatrizDeAdyacencia {
private:
    int numNodos;
    vector<vector<bool>> matriz;
public:
    // Constructor
    MatrizDeAdyacencia(int numNodos) {
        this->numNodos = numNodos;
        matriz.resize(numNodos, vector<bool>(numNodos, false));
    }

    // Agregar una arista
    void AgregarArista(int nodo1, int nodo2) {
        if (nodo1 >= 0 && nodo1 < numNodos &&
            nodo2 >= 0 && nodo2 < numNodos) {

            matriz[nodo1][nodo2] = true;
            matriz[nodo2][nodo1] = true; // Grafo no dirigido
        }
        else {
            cout << "Nodos no validos" << endl;
        }
    }

    // Mostrar los nodos
    void MostrarNodos() {
        cout << "Nodos en el grafo:" << endl;

        for (int i = 0; i < numNodos; i++) {
            cout << "Nodo " << i << endl;
        }
    }
    // Mostrar las aristas
    void MostrarAristas() {
        cout << "Aristas en el grafo:" << endl;

        for (int i = 0; i < numNodos; i++) {
            for (int j = i + 1; j < numNodos; j++) {
                if (matriz[i][j]) {
                    cout << "Arista entre Nodo "
                         << i << " y Nodo "
                         << j << endl;
                }
            }
        }
    }
};

int main() {
    int numNodos = 5;

    MatrizDeAdyacencia grafo(numNodos);

    grafo.AgregarArista(0, 1);
    grafo.AgregarArista(0, 2);
    grafo.AgregarArista(1, 3);
    grafo.AgregarArista(2, 4);

    grafo.MostrarNodos();
    grafo.MostrarAristas();

    return 0;
}
