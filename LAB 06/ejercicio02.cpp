#include <iostream>
using namespace std;
//Clase Nodo
class Nodo{
    public:
        int key;
        Nodo* left;
        Nodo* right;
        //Constructor
        Nodo(int item){
            key = item;
            left = nullptr;
            right = nullptr;
        }
};
//Clase Arbol Binario de Busqueda
class ArbolBinarioBusqueda{
    private:
        Nodo* root;
        //Recorrido Inorden
        void inorder(Nodo* nodo){
            if(nodo != nullptr){
                inorder(nodo->left);
                cout << nodo->key << " ";
                inorder(nodo->right);
            }
        }
    public:
        //Constructor
        ArbolBinarioBusqueda(){ root = nullptr;}

        //Insercion iterativa
        void insertar(int x){
            Nodo* temp = new Nodo(x);
            //Si el arbol esta vacio
            if(root == nullptr){
                root = temp;
                return;
            }
            //Buscar el padre del nuevo nodo
            Nodo* parent = nullptr;
            Nodo* curr = root;

            while(curr != nullptr){
                parent = curr;
                if(x < curr->key){
                    curr = curr->left;
                }
                else if(x > curr->key){
                    curr = curr->right;
                }
                else{
                    //La clave ya existe
                    cout << "La clave " << x << " ya existe" << endl;
                    return;
                }
            }
            //Insertar nuevo nodo
            if(x < parent->key){
                parent->left = temp;
            }
            else{
                parent->right = temp;
            }
        }
        //Metodo para imprimir en orden
        void imprimirInorden(){
            inorder(root);
            cout << endl;
        }
};
//Funcion principal
int main(){
    ArbolBinarioBusqueda abb;
    abb.insertar(50);
    abb.insertar(30);
    abb.insertar(20);
    abb.insertar(40);
    abb.insertar(70);
    abb.insertar(60);

    abb.insertar(50);
    abb.insertar(50);
    abb.insertar(50);

    cout << "Recorrido en orden del BST:" << endl;
    abb.imprimirInorden();

    return 0;
}