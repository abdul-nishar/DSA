#include <iostream>

using namespace std;

void reverse(int *arr, int low, int high) {
    while (low < high) {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}
void leftRotateByOne(int *arr, int n, int k){
    int newK = k % n;
    reverse(arr,0,newK-1);
    reverse(arr,newK,n-1);
    reverse(arr,0,n-1);
}

int main() {
    int numbersArray[] = {1,2,3,4,5,6,7,8,9};
    leftRotateByOne(numbersArray, 9, 3);
    for(int i = 0; i < sizeof(numbersArray)/sizeof(int);i++){
        cout<<numbersArray[i]<<" ";
    }
    return 0;
}