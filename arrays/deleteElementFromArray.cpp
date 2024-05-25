#include <iostream>
#include <string>

using namespace std;

string deleteElementFromArray(int *array, int n, int element) {
    bool found = false;
    for(int i=0; i<n; i++){
        if(array[i] == element) found = true;
        if (found) {
            array[i] = array[i+1];
        }
    }
    if(!found) return "Element not found";

    return "Element removed from array";
}

int main() {
    int arrayOfNumbers[7] = {8,3,5,2,73,4,1};
    cout<<deleteElementFromArray(arrayOfNumbers, sizeof(arrayOfNumbers) / sizeof(int), 12)<<endl;
    for(int i = 0; i < sizeof(arrayOfNumbers)/ sizeof(int); i++){
        cout<<arrayOfNumbers[i]<<" "<<endl;
    } 
    return 0;
}