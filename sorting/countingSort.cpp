#include <iostream>
#include <vector>
using namespace std;

/*
// Valid for intergers not for general purpose
void countingSort(int arr[], int n, int k) {
    vector<int> newArr(k,0);

    for(int i=0;i<n;i++){
        newArr[arr[i]]++;
    }

    int j = 0;
    for(int i=0;i<=k;i++){
        int count = newArr[i];
        while(count > 0){
            arr[j++] = i;
            count--;
        }
    }
}
*/


// General Purpose Implementation
void countingSort(int arr[], int n) {
	int low = INT_MAX;
	int high = INT_MIN;
	
	for(int i=0;i<n;i++){
			if(arr[i]<low) low = arr[i];
			if(arr[i]>high) high = arr[i];
	}	
	
	int k = high - low + 1;
    vector<int> newArr(k,0);

    for(int i=0;i<n;i++){
        newArr[arr[i]-low]++;
    }
    
    for(int i=1;i<k;i++) newArr[i] = newArr[i] + newArr[i-1];

    vector<int> output(n);

// We start the loop from n-1 so that we can maintain stable sorting
    for(int i=n-1;i>=0;i--){
        output[newArr[arr[i]-low] - 1] = arr[i];
        newArr[arr[i]-low]--;
    }

    for(int i=0;i<n;i++) arr[i] = output[i];
}

int main(){
    int numbersArray[] = {0,3,3,0,-1,0};
    countingSort(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    for(int i = 0; i < sizeof(numbersArray)/sizeof(numbersArray[0]); i++) cout << numbersArray[i] << " ";
    return 0;
}