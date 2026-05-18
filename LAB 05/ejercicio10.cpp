#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main (){
    queue<string> cola;
    
    cola.push("apple");
    cola.push("banana");
    cola.push("cherry");

    cout << "Cola: ";
    queue<string> temp = cola;
    while (!temp.empty()){
        cout << temp.front() << " ";
        temp.pop(); 
    }
    cout<< endl;

    string frony
    
}