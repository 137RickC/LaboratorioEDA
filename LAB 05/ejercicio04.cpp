#include <iostream>
#include <stack>
#include <string>
using namespace std;

 int main (){
    stack<string> pila;
    pila.push("Elemento 1");
    pila.push("Elemento 2");
    pila.push("Elemento 3");

    cout <<"Contenido de la pila" << endl;
    
    //Mostrar elementos de la pila
    while (!pila.empty()){
        cout<< pila.top()<<endl;
        pila.pop();
    }

    return 0;
 }