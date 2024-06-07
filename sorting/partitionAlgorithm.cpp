#include <iostream>
using namespace std;

void partitionAlgo(int arr[], int n, int p) {
    int countLeft = 0, countRight = 0;
    int newArr[n], p1=0, p2=n-1;

    for(int i=0; i<n; i++){
        if(i==p) continue;
        if(arr[i]<=arr[p]) {
            newArr[p1] = arr[i];
            p1++;
        } else {
            newArr[p2] = arr[i];
            p2--;
        }
    }

    newArr[p1] = arr[p]; 

    for(int i=0; i<n;i++) arr[i] = newArr[i];

}

int main(){
    int numbersArray[] = {3,8,6,12,10,7};
    for(int i=0; i<6; i++) cout << numbersArray[i] << " ";
    partitionAlgo(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]), 1);
    for(int i=0; i<6; i++) cout << numbersArray[i] << " ";

    return 0;
}