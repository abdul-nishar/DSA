#include <iostream>

using namespace std;

int maxSumCircularSubArray(int arr[], int n){
    int minValueIndex = 0;

    for (int i = 1; i < n; i++) minValueIndex = arr[minValueIndex] < arr[i] ? minValueIndex : i;

    if(arr[minValueIndex]<0) minValueIndex += 1;

    int res = arr[minValueIndex];
    int curMax = 0;
    int i = minValueIndex;

    for(; i < n ; i++){
        curMax = max(arr[i], arr[i]+curMax);
        res = max(res, curMax);
    }

    if(minValueIndex>0){
        for(int i=0; i < minValueIndex ; i++){
            curMax = max(arr[i], arr[i]+curMax);
            res = max(res, curMax);
        }
    }
   
    return res;
}

int main(){
    int numbersArray[]= {10,-3,-4,7,6,5,-4,-1};
    cout << maxSumCircularSubArray(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    return 0;
}