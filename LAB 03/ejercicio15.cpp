#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr ={3,7,2,9,1};
    int max = arr[0];

    for(int i=1; i<arr.size(); i++)
        if(arr[i]> max)
            max=arr[i];
    
    cout<<"Mayor: "<< max;
    
    return 0;
}