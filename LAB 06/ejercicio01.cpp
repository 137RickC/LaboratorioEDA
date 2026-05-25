# include <iostream>
using namespace std;

class ArbolBinarioOrdenado{
    private:
        //calse nodo
        class Nodo{
            public:
            int info;
            Nodo* izq;
            Nodo* der;

            Nodo(int valor){
                info = valor;
                izq = nullptr;
                der = nullptr;
            }
        };
        Nodo* raiz;
        //Recorrido PRE-orden
        void imprimirPre(Nodo* reco){
            if (reco !=nullptr){
                cout << reco->info <<" ";
                imprimirPre(reco->izq);
                imprimirPre(reco->der);
            }
            
        }
        //Recorrido IN-orden
        void imprimirIn(Nodo* reco){
            if (reco !=nullptr){
                imprimirPre(reco->izq);
                cout << reco->info <<" ";
                imprimirPre(reco->der);
            }
        }
        //Recorrido POS-orden
        void imprimirPos(Nodo* reco){
            if (reco !=nullptr){
                imprimirPre(reco->izq);
                imprimirPre(reco->der);    
                cout << reco->info <<" ";
            }
        }
    public:
        //Constructor
        ArbolBinarioOrdenado(){
            raiz= nullptr;
        }
        //insertar
        void insertar(int info){
            Nodo* nuevo = new Nodo(info);
            if(raiz == nullptr){ raiz = nuevo; }
            else{
                Nodo* anterior = nullptr;
                Nodo* reco = raiz;
                while(reco != nullptr){
                    anterior= reco;
                    if (info < reco->info){ reco->izq;}
                    else{ reco = reco->der; }
                }
                if(info < anterior-> info){anterior -> izq = nuevo; }
                else{ anterior-> der = nuevo; }
            }
        }
        //Metodo publico  Preorden 
        void imprimirPre(){
            imprimirPre(raiz);
            cout << endl;
        }
        //Metodo publico  Ineorden 
        void imprimirIn(){
            imprimirIn(raiz);
            cout << endl;
        }
        //Metodo publico  Posorden 
        void imprimirPost(){
            imprimirPos(raiz);
            cout << endl;
        }
};
int main (){
    ArbolBinarioOrdenado abo;
    abo.insertar(100);
    abo.insertar(50);
    abo.insertar(25);
    abo.insertar(75);
    abo.insertar(150);

    cout << "Inprecion Preorden :"<< endl;
    abo.imprimirPre();

    cout << "Inprecion Inorden :"<< endl;
    abo.imprimirIn();
    
    cout << "Inprecion Preorden :"<< endl;
    abo.imprimirPost();
    
    return 0;

}