#include <iostream>

using namespace std;

int secondLargestElementIndex(int a[], int n){
    int maxIndex = 0, secondMaxIndex=1;
    for(int i=1; i<n; i++) {
        if(a[i]>a[maxIndex]){
            secondMaxIndex=maxIndex;
            maxIndex=i;
        } else if (a[maxIndex] > a[i] && a[i]>a[secondMaxIndex]) secondMaxIndex = i;
    }

    if(a[secondMaxIndex] == a[maxIndex]) return -1;

    return secondMaxIndex;
}

int main() {
    int numbersArray[] = {34,8,10,3,2,80,30,33,1};
    cout<<secondLargestElementIndex(numbersArray,sizeof(numbersArray) / sizeof(int)); 
    return 0;
}