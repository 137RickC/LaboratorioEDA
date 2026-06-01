#include <iostream>
using namespace std;
// clase nodo
class Nodo{
    public:
        int data;
        Nodo* left;
        Nodo* right;

        //Constructor
        Nodo(int item){
            data = item;
            left = nullptr;
            right = nullptr;
        }
};

//Clase de Arbol Binario de Busqueda
class ArbolBinarioBusqueda{
    private:
        Nodo* root;
    public:
    ArbolBinarioBusqueda(){ root = nullptr;}

    //metodo para asignar la raiz
    void  crearArbolEjemplo(){
        root = new Nodo (20);

        root->left = new Nodo(8);
        root->right = new Nodo(22);

        root->left->left = new Nodo(4);
        root->left->right = new Nodo(12);
        
        root->left->right->left = new Nodo(10);
        root->left->right->right = new Nodo(14);
    }
    //Funcion de Busqueda iterativa
    bool buscar(int x){
        Nodo* curr = root;
        while (curr != nullptr){
            //si el  nodo actual contine x
            if(curr->data == x) {return true;}

            else if(curr->data < x) {curr = curr->right;} 
            else curr = curr->left;
        }
        return false;
    }
};
//funcion principal
int manin(){
    ArbolBinarioBusqueda abb;

    abb.crearArbolEjemplo();
    int x = 12;

    if( abb.buscar(x)) cout << "El valor " << x << "SI exuste ele en el arbool" <<  endl; 
    else cout << "El valor  "<< x << "NO existe en el arbol"<< endl;  
    
    return 0;
}