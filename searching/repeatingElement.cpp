#include <iostream>
using namespace std;

int repeatingElement(int arr[], int n) {
    int maxEl = arr[0], arrSum = arr[0];
    for(int i=1;i<n;i++){
        if(maxEl<arr[i]) maxEl = arr[i];
        arrSum += arr[i];
    }

    int sum = (maxEl*(maxEl+1))/2;
    int diff = arrSum - sum;
    int temp = n - (maxEl);

    int result;
    for(int i = 0; i <= maxEl; i++){
        if(i*temp == diff) result = i;
    }
    return result;
}

int main(){
    int numbersArray[] = {1,2,3,4,3};
    cout << repeatingElement(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    return 0;
}