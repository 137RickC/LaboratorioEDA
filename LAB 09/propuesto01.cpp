#include <iostream>
#include <vector>
#include <unordered_set>

bool verificarElementos(const std::vector<int>& A, const std::vector<int>& B) {
    // Insertamos todos los elementos del arreglo B en una tabla hash
    std::unordered_set<int> hashB(B.begin(), B.end());

    // Verificamos si cada elemento de A está presente en la tabla hash de B
    for (int elemento : A) {
        if (hashB.find(elemento) == hashB.end()) {
            return false; // Con un solo elemento que no esté, ya es falso
        }
    }
    return true; // Todos los elementos están presentes
}
void imprimir(std::vector<int> vec ){
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std:: cout << std:: endl;
    
}
int main() {
    std::vector<int> A = {2, 4, 8};
    std::vector<int> B = {1, 2, 3, 4, 7, 8, 9};

    imprimir(A);
    imprimir(B);

    std::cout << " Verificacion de Arreglos " << std::endl;
    if (verificarElementos(A, B)) {
        std::cout << "Resultado: Todos los elementos de A estan en B." << std::endl;
    } else {
        std::cout << "Resultado: NO todos los elementos de A estan en B." << std::endl;
    }

    return 0;
}