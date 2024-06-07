#include <iostream>
using namespace std;

void actualFunc(int arr1[], int n, int arr2[], int m){
    int p1 = 0,p2=0;

    while(p2<m && p1<n){
        if(p2!=m-1 && arr2[p2]==arr2[p2+1]) {p2++;continue;}
        if(arr2[p2] == arr1[p1]) {cout << arr2[p2]<<" ";p2++;p1++;}
        else if(arr2[p2] > arr1[p1]) p1++;
        else p2++;
    }
}

void findIntersection(int arr1[], int n, int arr2[], int m) {
    if(n>m) actualFunc(arr1, n, arr2, m);
    else actualFunc(arr2, m, arr1, n);
}

int main(){
    int numbersArray1[] = {3,5,10,10,10,15,15,20};
    int numbersArray2[] = {5,10,10,15,30};

    findIntersection(numbersArray1, sizeof(numbersArray1)/sizeof(numbersArray1[0]), numbersArray2, sizeof(numbersArray2)/sizeof(numbersArray2[0]));
    return 0;
}