#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool equilibrado(string expresion){

    stack<char> pila;

    for(char c : expresion){

        if(c == '(' || c == '[' || c == '{'){ pila.push(c); }

        else if(c == ')' || c == ']' || c == '}'){
            if(pila.empty()){ return false; }

            if(
                (c == ')' && pila.top() != '(') ||
                (c == ']' && pila.top() != '[') ||
                (c == '}' && pila.top() != '{')
            ){ return false; }
            pila.pop();
        }
    }
    return pila.empty();
}

int main(){

    string expresion = "{[()]}";

    if(equilibrado(expresion)){
        cout << expresion <<" La expresion esta equilibrada" << endl;
    }
    else{
        cout << "La expresion NO esta equilibrada" << endl;
    }

    return 0;
}