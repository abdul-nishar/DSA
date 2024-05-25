#include <iostream>

using namespace std;

// Method - 1 -> Time Complexity = O(n) and Auxiliary Space = O(n)

// bool equilibriumPoint(int arr[], int n){
//     int sumArray[n];
//     int sum = 0;
//     for(int i = 0; i < n;i++){
//         sum += arr[i];
//         sumArray[i] = sum;
//     } 

//     if(sumArray[n-1]-sumArray[0] == 0) return true;
//     if(sumArray[n-2]== 0) return true;
//     for(int i = 1; i < n; i++){
//         if(sumArray[i-1] == sumArray[n-1] - sumArray[i]) return true;
//     }

//     return false;
// }

// Method - 2 -> Time Complexity = 0(n) and Auxiliary Space = O(1)
// bool equilibriumPoint(int arr[], int n){
//     int rsum = 0;
//     for(int i = 0; i < n; i++) rsum += arr[i];

//     int lsum = 0;
//     for(int i = 0; i < n; i++) {
//         rsum -= arr[i];
//         if(rsum == lsum) return true;
//         lsum += arr[i];
//     }

//     return false;
// }


bool equilibriumPoint(int arr[], int n){
    int rsum = 0;
    for(int i = 0; i < n; i++) rsum += arr[i];

    int lsum = 0, count =  1;
    for(int i = 0; i < n; i++) {
        rsum -= arr[i];
        lsum += arr[i];
        if(rsum == 2*lsum) count++;
        if(2*rsum == lsum) count++;
    }

    return count == 3;
}

int main(){
    int numbersArray[] = {3,2,5,1,1,5};
    cout << boolalpha << equilibriumPoint(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
}