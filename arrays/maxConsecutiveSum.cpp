#include <iostream>

using namespace std;

int maxConsecutiveSum(int arr[], int n, int k){
    int maxValue = 0;
    int startEl = 0;
    for(int i = 0; i < k; i++) maxValue += arr[i];

    int temp = maxValue;
    for(int i = k; i<n; i++){ 
        temp = temp + arr[i] - arr[startEl++];
        maxValue = max(maxValue, temp);
    }

    return maxValue;
}

int main() {
    int numbersArray[] = {16, 12, 9, 19, 11, 8};
    cout << maxConsecutiveSum(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]), 3);
    return 0;
}