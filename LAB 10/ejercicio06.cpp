#include <iostream>
#include <vector>
using namespace std;

class MatrizDeAdyacencia {
private:
    int n;
    vector<vector<int>> matriz;
public:
    // Constructor
    MatrizDeAdyacencia(int n) {
        this->n = n;
        // Inicializar la matriz en 0
        matriz.resize(n, vector<int>(n, 0));
    }
    // Agregar una arista
    void agregar(int i, int j) {
        matriz[i][j] += 1;
    }
    // Remover una arista
    void remover(int i, int j) {
        if (matriz[i][j] > 0)
            matriz[i][j] -= 1;
    }

    // Imprimir la matriz
    void imprimir() {
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {
                cout << matriz[i][j] << "  ";
            }

            cout << endl;
        }
    }
};
int main() {
    MatrizDeAdyacencia matriz(5);

    matriz.agregar(0, 1);
    matriz.agregar(0, 1);
    matriz.agregar(0, 2);
    matriz.agregar(0, 3);

    matriz.agregar(1, 0);
    matriz.agregar(1, 0);
    matriz.agregar(1, 4);

    matriz.agregar(2, 0);
    matriz.agregar(2, 3);
    matriz.agregar(2, 4);

    matriz.agregar(3, 0);
    matriz.agregar(3, 2);

    matriz.agregar(4, 1);
    matriz.agregar(4, 2);
    matriz.agregar(4, 4);
    matriz.agregar(4, 4);

    matriz.imprimir();

    return 0;
}
