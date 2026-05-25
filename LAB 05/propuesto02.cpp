#include <iostream>
#include <stack>
using namespace std;

class colaWStack{
    private:
        stack<int> pEntrada;
        stack<int> pSalida;

        void invertirOrden(){
            if(pSalida.empty()){
                while (!pEntrada.empty()){
                    pSalida.push(pEntrada.top());
                    pEntrada.pop();
                }
            }
        }

    public:

    void Enqueue(int valor){ pEntrada.push(valor); }
    void Dequeue(){
        invertirOrden();

        if(!pSalida.empty()){ pSalida.pop();}
        else{ cout << "La cola esta vacia" << endl; }
    }

    int front(){
        invertirOrden();

        if(!pSalida.empty()){ return pSalida.top(); }
        else{
            cout << "La cola esta vacia" << endl;
            return -1;
        }
    }

    bool empty(){ return pEntrada.empty() && pSalida.empty(); }

    void mostrarCola(){

        if(empty()){
            cout << "La cola esta vacia" << endl;
            return;
        }

        invertirOrden();

        stack<int> auxSalida = pSalida;
        stack<int> auxEntrada;

        while(!auxSalida.empty()){
            cout << "[ " << auxSalida.top() << " ] ";
            auxSalida.pop();
        }

        auxEntrada = pEntrada;

        stack<int> temp;

        while(!auxEntrada.empty()){
            temp.push(auxEntrada.top());
            auxEntrada.pop();
        }

        while(!temp.empty()){
            cout << "[ " << temp.top() << " ] ";
            temp.pop();
        }

        cout << endl;
    }
};

int main(){

    colaWStack q;

    q.Enqueue(10);
    q.Enqueue(40);
    q.Enqueue(30);
    q.Enqueue(60);
    q.Enqueue(20);

    cout << "Los elementos de la cola son: " << endl;
    q.mostrarCola();

    cout << q.front() << " es el elemento en frente de la cola" << endl;

    cout << "Eliminamos e insertamos un elemento a la cola" << endl;

    q.Dequeue();
    q.Enqueue(80);

    cout << "Los elementos de la cola son: " << endl;
    q.mostrarCola();

    return 0;
}