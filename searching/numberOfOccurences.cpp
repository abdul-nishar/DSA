#include <iostream>
using namespace std;

int numberOfOccurences(int arr[], int n, int element) {
    int firstOccurence = lower_bound(arr, arr+n, element) - arr;
    int lastOccurence = upper_bound(arr, arr+n, element) - arr;
    return lastOccurence - firstOccurence;
}

// int firstOccurence(int arr[],  int low, int high, int element){
//     if(low > high) return -1;
//     int mid = (high+low)/2;
//     if(mid==0 || arr[mid]==element && arr[mid-1]<element) return mid;
//     else if(element>arr[mid]) return firstOccurence(arr, mid+1, high, element);
//     else return firstOccurence(arr, low, mid-1, element);
// }

// int lastOccurence(int arr[],  int low, int high, int element){
//     if(low > high) return -1;
//     int mid = (high+low)/2;
//     if(mid==0 || (arr[mid]==element && arr[mid+1]>element)) return mid;
//     else if(element>=arr[mid]) return lastOccurence(arr, mid+1, high, element);
//     else return lastOccurence(arr, low, mid-1, element);
// }

// int numberOfOccurences(int arr[], int n, int element){
//     int firstIndex = firstOccurence(arr, 0, n-1, element);
//     int lastIndex = lastOccurence(arr, 0, n-1, element);
//     if(firstIndex<0 && lastIndex<0) return 0;
//     return lastIndex - firstIndex + 1;
// }

int main(){
    int numbersArray[] = {0,0,0,0};
    cout << numberOfOccurences(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]), 1);

    return 0;
}