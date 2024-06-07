#include <iostream>
using namespace std;


// Method - 1 : Personal Attempt
int findMinimum(int arr[], int start, int n){
    int minValIdx = start;
    for(int i=start+1; i<n;i++) if(arr[i]<arr[minValIdx]) minValIdx = i;

    return minValIdx;
}
void selectionSort(int arr[], int n) {

    for(int i=0; i<n; i++){
        int minValueIndex = findMinimum(arr, i, n);
        swap(arr[i], arr[minValueIndex]);
    }
}

// Method - 2 : Actual Algorithm

void selectionSort(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        int min_idx = i;
        for (int j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

int main(){
    int numbersArray[] = {64,25,12,22,11};
    selectionSort(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    for( auto value: numbersArray) cout << value << " ";
    return 0;
}