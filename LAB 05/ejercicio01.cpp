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

    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << s.pop() << " sacado de la pila" << endl;
    cout << "El elemto en la cima es: " <<  s.peek() << endl;
    cout << "Elementos presentes en la pila: ";
    while (!s.isEmpty()){
        cout<< s.peek() << " ";
        s.pop();
    }
    
    return 0;
}