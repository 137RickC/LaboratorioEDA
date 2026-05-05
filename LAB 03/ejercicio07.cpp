#include <iostream>
using namespace std;
int main(){
    int n = 3;
    int* arr = new int [n]{1,2,3};

    int* temp = new int[5];
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];

    delete[] arr;
    arr = temp;

    for (int i = 0; i < 5; i++)
        cout<< arr[i]<< " ";
    
    delete[] arr; 
    return 0;

}