#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    // Method-1 : Personal Attempt
    for(int i=1;i<n;i++){
        int p1 = i, p2 = i-1;
        while(p2>=0 && arr[p1]<arr[p2]){
            swap(arr[p1], arr[p2]);
            p1--;p2--;
        }
    }
    
    // Method-2 : Actual Algorithm
    for (int i = 1; i < n; i++) { 
       int key = arr[i]; 
       int j = i-1; 
     
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
}

int main(){
    int numbersArray[] = {12,11,13,5,6};
    insertionSort(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    for(auto value : numbersArray) cout << value << " ";
    return 0;
}