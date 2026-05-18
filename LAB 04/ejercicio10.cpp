#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    list<int> list;
    // Añadir elementos
    list.push_back(123);
    list.push_back(12);
    list.push_back(11);
    list.push_back(1134);
    // Mostrar LinkedList
    cout << "LinkedList: ";
    for (int x : list) {
        cout << x << " ";
    }
    cout << endl;

    //CONVERSIÓN A ARRAY (usando vector)
    vector<int> arr(list.begin(), list.end());
    // Mostrar array
    cout << "Despues de convertir LinkedList a un Array: ";
    for (int element : arr) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}