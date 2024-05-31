#include <iostream>
using namespace std;

bool triplet(int arr[], int n, int sum) {
    int low=0,high = n-1;
    while(low<high){
        int mid=(low+high)/2;
        if(low>=mid || mid>=high) return false;
        int curSum = arr[low] + arr[high] + arr[mid];
        if(curSum == sum) return true;
        else if(curSum > sum) high--;
        else low++;
    }
    return false;
}

// bool pairSum(int arr[], int n, int startIndex, int sum){
//     int low = startIndex, high = n-1;
//     while(low<high){
//         int curSum = arr[low]+arr[high];
//         if(curSum==sum) return true;
//         else if(curSum > sum) high--;
//         else low++;
//     }
//     return false;
// }

// bool triplet(int arr[], int n, int sum) {
//     for(int i = 0; i<n-1 ; i++){
//         int curSum = sum - arr[i];
//         if(pairSum(arr, n , i+1, curSum)) return true;
//     }

//     return false;
// }

int main(){
    int numbersArray[] = {1,2,3,4,7,9,10,10,11,23};
    cout << triplet(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]), 6);
    return 0;
}