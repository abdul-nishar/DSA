#include <iostream>

using namespace std;

bool isArraySorted(int a[], int n){
    int min = a[0];
    for(int i = 1; i < n;i++) {
        if(a[i] < min) return false;
        else min = a[i];
    }

    return true;
}

int main() {
     int numbersArray[] = {8,10,10,12};
    cout<<isArraySorted(numbersArray,sizeof(numbersArray) / sizeof(int)); 
    return 0;
}