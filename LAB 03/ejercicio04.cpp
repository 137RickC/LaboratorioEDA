#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    // entrada de datos en el arr
    for (int i=0; i<n; i++)
        cin >> arr[i]; 
    // imprimir en consola los datos del arr
    for (int i=0; i<n; i++)
        cout << arr[i] << " "; 
     
    delete[] arr;
    return 0;
}