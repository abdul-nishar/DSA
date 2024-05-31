#include <iostream>
#include <climits>
using namespace std;

bool isPossible(int arr[], int n, int k, int value){
    int curSum = 0, count = 1;
    for(int i = 0; i < n;i++){
        if(arr[i] > value) return false;
        if(curSum + arr[i]> value){
            count++;
            curSum = arr[i];
            if(count > k) return false;
        }else curSum += arr[i];
    }

    return true;
}

int allocatePages(int arr[], int n, int k) {

    if(k>n) return -1;
    int arrSum = 0;

    for(int i = 0; i < n; i++) arrSum += arr[i]; 

    int result = INT_MAX;
    int start = 0, end = arrSum;

    while(start<=end){
        int temp = (start+end)/2;
        
        if(isPossible(arr, n, k, temp)) {
            result = temp;
            end = temp - 1;
        }else start = temp + 1;
    }

    return result;
}

int main(){
    int numbersArray[] = {12, 34, 67, 90};
    cout << allocatePages(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]), 2);
    return 0;
}