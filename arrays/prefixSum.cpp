#include <iostream>

using namespace std;

int getSum(int l, int r, int* arr){
    if(l!=0) return arr[r] - arr[l-1];
    else return arr[r];
}

int main() {
    int numbersArray [] = {2,8,3,9,6,5,4};
    int sumArray[sizeof(numbersArray)/sizeof(numbersArray[0])];
    int sum = 0;
    for(int i = 0; i< sizeof(numbersArray)/sizeof(numbersArray[0]); i++){
        sum+=numbersArray[i];
        sumArray[i] = sum;
    }
    cout << getSum(0,2, sumArray)<< endl;
    cout << getSum(1,3, sumArray)<< endl;
    cout << getSum(2,6, sumArray)<< endl;
    return 0;
}