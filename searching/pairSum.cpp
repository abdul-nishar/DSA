#include <iostream>
using namespace std;

bool pairSum(int arr[], int n, int sum) {
    int high = n-1, low=0;
    while(low<high){
        if(arr[high]+arr[low]==sum) return true;
        else if(arr[high]+arr[low]>sum) high--;
        else low++;
    }

    return false;
}

int main(){
    int numbersArray[] = {2,3,8,11};
    cout << pairSum(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]), 14);
    return 0;
}