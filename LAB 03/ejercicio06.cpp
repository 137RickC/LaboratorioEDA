#include <iostream>
using namespace std;

int main(){
    int* a = new int[3]{1,2,3};
    int* b = new int[3];

    for (int i = 0; i < 3; i++)
        b[i] = a[i];
    for (int i = 0; i < 3; i++)
        cout << b[i]<< " ";
    
    delete[] a;
    delete[] b;
    return 0;
}