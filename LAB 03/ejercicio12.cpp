#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr ={1,2,3,4};
    int suma = 0;  

    for (int i = 0; i < arr.size(); i++)
        suma +=arr[1];
    cout<< "Suma: "<< suma;

    return 0;
}