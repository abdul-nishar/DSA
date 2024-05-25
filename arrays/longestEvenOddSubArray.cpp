#include <iostream>

using namespace std;

int longestEvenOddSubArray(int arr[],int n){
    int result = 0;
    int temp = 1;
    int toggleInt = arr[0]%2;

    for(int i=1;i<n;i++){
        if(arr[i]%2 != toggleInt) {
            temp++;
            toggleInt = arr[i]%2;
        } else {
            if(temp > result) result = temp;
            temp = 1;
        }
    }

    return result > temp ? result : temp;
}

int main(){
    int numbersArray[] = {5,10,20,6,3,8};
    cout << longestEvenOddSubArray(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    return 0;
}