#include <iostream>
using namespace std;

int binarySearch(int arr[], int element, int low, int high) {
    // Iterative Solution
    // int low = 0, high = n-1;

    // while(high>=low) {
    //     int mid = (high + low)/2;
    //     if(arr[mid] == element) return mid;
    //     else if(arr[mid] < element) low = mid + 1;
    //     else high = mid - 1;
    // }

    // return -1;

    //Recursive Solution
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==element) return mid;
    if(arr[mid]>element) return binarySearch(arr, element,0, mid-1);
    else return binarySearch(arr, element,mid+1, high);

}

int main(){
    int numbersArray[] = {10,20,30,40,50};
    int arraySize = sizeof(numbersArray)/sizeof(numbersArray[0]);
    cout << binarySearch(numbersArray, 40, 0, arraySize-1);
    return 0;
}