#include <iostream>

using namespace std;

int profitStocks(int arr[], int n){
    int profit = 0;
    
    for(int i=1; i<n;i++){
        if(arr[i]>arr[i-1]) profit += arr[i] - arr[i-1];
    }

    return profit;
}

int main(){
    int numbersArray[] = {1,5,3,1,2,8};
    cout << profitStocks(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    return 0;
}