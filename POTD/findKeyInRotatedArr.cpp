#include <iostream>
#include <vector>

using namespace std;

int maxElementIndex(vector<int> arr){
    int low = 0, high = arr.size() - 1;
    while(low<high){
        int mid = low + (high - low) / 2;
        
        if(arr[mid] > arr[mid+1]) return mid;
        
        if (arr[mid] > arr[low]) low = mid + 1;
        else high = mid;
    }
    
    return low;
}

int binarySearch(const vector<int>& arr, int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int search(vector<int>& arr, int key) {
    int n = arr.size();
    int maxElementIdx = maxElementIndex(arr);

    int result = binarySearch(arr, 0, maxElementIdx, key);
    if (result != -1) return result;

    return binarySearch(arr, maxElementIdx + 1, n - 1, key);
}

int main(){
    vector<int> numsArr = {5,6,7,8,9,10,1,2,3,4};
    cout << search(numsArr, 10);
}