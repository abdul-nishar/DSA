#include <iostream>
using namespace std;

// Method - 1 : Time Complexity = O(N^2)

// int countInversions(int arr[], int n) {
//     int count=0;
//     for(int p1=0;p1<n-1;p1++){
//         int p2 = p1+1;
//         while(p2<n){
//             if(arr[p1] > arr[p2]) count++;
//             p2++;
//         }
//     }
//     return count;
// }

// Method - 2 : Time Complexity = O(N*logN) + Space Complexity = O(N)

long long int countAndMerge(long long array[], long left, long mid, long right) {
    long long * leftArray = new long long [mid - left + 1];
    long long * rightArray = new long long [right - mid];
    
    for (auto i = 0; i < mid - left + 1; i++) leftArray[i] = array[left + i];
    for (auto j = 0; j < right - mid; j++) rightArray[j] = array[mid + 1 + j];
    
    long long int count = 0;
    long indexOfleftArray = 0,indexOfRightArray= 0,indexOfMergedArray= left;
    
    while (indexOfleftArray < (mid-left+1)
           && indexOfRightArray < right-mid) {
        if (leftArray[indexOfleftArray]
            <= rightArray[indexOfRightArray]) {
            array[indexOfMergedArray]
                = leftArray[indexOfleftArray];
            indexOfleftArray++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfRightArray];
            indexOfRightArray++;
            count=count+(mid-left+1)-indexOfleftArray;
        }
        indexOfMergedArray++;
    }

    while (indexOfleftArray < mid - left + 1) {
        array[indexOfMergedArray]
            = leftArray[indexOfleftArray];
        indexOfleftArray++;
        indexOfMergedArray++;
    }

    while (indexOfRightArray < right - mid) {
        array[indexOfMergedArray]
            = rightArray[indexOfRightArray];
        indexOfRightArray++;
        indexOfMergedArray++;
    }
    
    delete[] leftArray;
    delete[] rightArray;

    return count;
}
    
long long int countInversions(long long arr[], long left, long right) {
    long long int count = 0;
    if (right > left) {
        long mid = (left + right) / 2;

        count += countInversions(arr, left, mid);
        count += countInversions(arr, mid + 1, right);

        count += countAndMerge(arr, left, mid, right);
    }

    return count;
}
    
long long int inversionCount(long long arr[], long long N) {
    long long int result = countInversions(arr, 0, N - 1);
    return result;
}

int main(){
    long long numbersArray[] = {2,4,1,3,5};
    cout << countInversions(numbersArray,0, sizeof(numbersArray)/sizeof(numbersArray[0])-1);
    return 0;
}