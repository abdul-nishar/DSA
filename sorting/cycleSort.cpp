#include <iostream>
using namespace std;

int cycleSort(int arr[], int n) {
    int itemIdx = 0, result = 0;
    for(int i=0; i<n; i++) {
        int count = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] < arr[itemIdx]) count++;
        }
        if(itemIdx >= count) itemIdx++;
        else {
            if(arr[itemIdx]!=arr[count]){swap(arr[itemIdx], arr[count]);result++;}
            else {
                int temp = count+1;
                while(temp < n && arr[temp]==arr[itemIdx]) temp++;
                swap(arr[temp], arr[itemIdx]);
            }
        }   
    }
    return result;
}

int main(){
    int numbersArray[] = {10,10,30,20};
    int numberOfSwaps = cycleSort(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    cout << numberOfSwaps <<endl;
    for(int i=0;i<sizeof(numbersArray)/sizeof(numbersArray[0]);i++) cout << numbersArray[i] << " "
;    return 0;
}