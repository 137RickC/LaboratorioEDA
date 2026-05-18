#include <iostream>
#include <queue>
using namespace std;

int main (){
    // Creando una cola de enteros vacia
    queue<int> q;
    //Mostrando la cola
    cout<<"Elementos de la cola: ";
    // verificar sis esta vacia
    if(q.empty()){
        cout << "La cola esta vacia "; 
    }
    cout<< endl;

    return 0;
}