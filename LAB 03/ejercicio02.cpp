#include <iostream>
using namespace std;

int main(){
    int* arr = new int[4]{1,2,3,4};
    int suma = 0;

    for (int i = 0; i < 4; i++)
        suma += arr[i];
    
    cout << "Suma: "<< suma;
    delete[] arr;
    return 0;
}