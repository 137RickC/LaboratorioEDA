#include <iostream>
using namespace std;
int main(){
    double* arr = new double[3]{1.5, 2.5, 3.5};
    for(int i=0; i<3; i++)
        cout <<arr[i]<< " ";
    delete[] arr;
    return 0;
    
}