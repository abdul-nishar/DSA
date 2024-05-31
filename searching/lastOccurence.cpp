#include <iostream>
using namespace std;

int lastOccurence(int arr[], int n, int element) {
    int low = 0, high = n-1;
    
    while(low<=high){
        int mid = (low + high) / 2;
        if(arr[mid] == element && ( mid == n-1 || arr[mid+1] > element)) return mid;
        else if (arr[mid] <= element) low = mid+1;
        else high = mid-1;
    }

    return -1;
}

int main(){
    int numbersArray[] = {8,10,10,12};
    cout << lastOccurence(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]), 7);
    return 0;
}