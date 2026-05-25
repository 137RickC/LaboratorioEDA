#include <iostream>
#include <queue>
using namespace std;

//Mostrar cola
void mostrarCola(priority_queue <int> pq){
    if(pq.empty()){
        cout<<"La cola esta vacia";
        return;
    }
    while (!pq.empty()){
        cout << "[ " << pq.top() << " ]";
        pq.pop();
    }
    cout<< endl;
}
int main (){
    priority_queue <int> cola;

    cola.push(10);
    cola.push(20);
    cola.push(15);
    cout << "Cola inicial: "<<endl;
    mostrarCola(cola);

    cout << "Elemento de prioridad: " << cola.top() << endl;
    
    cola.pop();
    cout << "Cola despues de borrar la prioridad:  " << endl;
    mostrarCola(cola);

    return 0;

}