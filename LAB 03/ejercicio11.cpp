#include <iostream>
#include <vector>
using namespace std;

int main (){
    vector<int> arr(5);
    for (int i = 0; i < 5; i++)
        arr[i]= i+1;
    
    for (int i = 0; i < 5; i++)
        cout<< arr[i]<< " "; 
    return 0; 
}