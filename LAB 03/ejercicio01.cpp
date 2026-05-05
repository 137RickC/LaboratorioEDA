#include <iostream>
using namespace std;

int main(){
    int n= 5;
    int* arr = new int[n];
    
    for(int i=0; i<n; i++)
        arr[i] = i+1;
    for(int i=0; i<n; i++)
        cout<< arr[i]<<endl;

    delete[] arr;
    return 0;
}