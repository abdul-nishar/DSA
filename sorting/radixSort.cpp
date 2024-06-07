#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n, int temp) {
	int low = INT_MAX;
	int high = INT_MIN;

    int powerOfTen = pow(10, temp);
	
	for(int i=0;i<n;i++){
			if(arr[i] % powerOfTen < low) low = arr[i] % powerOfTen;
			if(arr[i] % powerOfTen >high) high = arr[i] % powerOfTen;
	}	
	
	int k = high - low + 1;
    vector<int> newArr(k,0);

    for(int i=0;i<n;i++){
        newArr[(arr[i]%powerOfTen)-low]++;
    }
    
    for(int i=1;i<k;i++) newArr[i] = newArr[i] + newArr[i-1];

    vector<int> output(n);

// We start the loop from n-1 so that we can maintain stable sorting
    for(int i=n-1;i>=0;i--){
        output[newArr[(arr[i]%powerOfTen)-low] - 1] = arr[i];
        newArr[(arr[i]%powerOfTen)-low]--;
    }

    for(int i=0;i<n;i++) arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maxValue = INT_MIN;
    for(int i=0;i<n;i++) maxValue = max(maxValue, arr[i]);

    int passes = ceil(log10(maxValue));
    int temp = 1;
    while(temp <= passes){
        countingSort(arr, n, temp);
        temp++;
    }
}

int main(){
    int numbersArray[] = {319,212,6,8,100,50};
    radixSort(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    for(int i = 0; i < sizeof(numbersArray)/sizeof(numbersArray[0]);i++) cout << numbersArray[i] << " ";
    return 0;
}