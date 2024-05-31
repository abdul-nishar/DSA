#include <iostream>
using namespace std;

int binarySearch(int arr[] , int low, int high, int element){
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == element) return mid;
        else if(arr[mid] > element) high = mid-1;
        else low =mid+1;
    }

    return -1;
}

int searchInInfiniteArray(int arr[], int element) {
    if(arr[0] == element) return 0;
    int i = 1;
    while(arr[i]<element){
        i *= 2;
        if(arr[i] == element) return i;
    }

    return binarySearch(arr, (i/2)+1, i+1 , element);
}

int main(){
    int numbersArray[] = {}; // cannot define infinite array
    cout << searchInInfiniteArray(numbersArray, 100);
    return 0;
}