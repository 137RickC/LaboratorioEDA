#include <iostream>
#include <queue>

using namespace std;
class Stack {
    int top, cap;
    int* a;
    public:
        //Constructor
        Stack(int cap){
            this->cap = cap;
            top = -1;
            a = new int [cap];
        }
        //Push
        bool push(int x){
            if(top >= cap-1){
                cout <<"Desbordamiento de Pila"<< endl;
                return false; 
            }
            a[++top] = x;
            return true;
        }
        //Pop
        int pop (){
            if (top < 0){
                cout << "Desbordamiento por debajode Pila"<< endl;
                return 0;
            }
            return a[top--];
        }
        //Peek
        int peek (){
            if(top<0){
                cout <<"La pila esta vacia " <<endl; 
                return 0; 
            }
            return a[top];
        }
        //verificar si la pila esta vacia
        bool isEmpty (){
            return top < 0;
        }
        // Destructor para liberar memoria
        ~Stack(){
            delete[] a;
        }
};

int main() {

    // Cola de prioridad
    priority_queue<int> pq;

    // Insertar elementos
    pq.push(10);
    pq.push(20);
    pq.push(15);

    // Mostrar elementos
    cout << "Cola de prioridad: ";

    priority_queue<int> temp = pq;

    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;

    // Eliminar elemento con mayor prioridad
    pq.pop();

    // Mostrar cola resultante
    cout << "Cola despues de eliminar el mayor elemento: ";

    temp = pq;

    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;

    return 0;
}