#include <iostream>

using namespace std;

int moveZeroesToBack(int arr[], int n){
    int count = 0;
    for(int i = 0; i <n;i++){
        if(arr[i] != 0) swap(arr[i], arr[count++]);
    }

    return count;
}

bool subArraywithGivenSum(int arr[], int n, int sum){
    int newSize = moveZeroesToBack(arr, n);
    int movingIndex = 0;
    int temp = arr[0];

    for(int i = 1; i < newSize;i++){
        if(temp == sum)return true;
        if(temp > sum) {
            temp -= arr[movingIndex++];
            i--;
            continue;
        }
        temp += arr[i];
    }

    return false;
    
}

int main() {
    int numbersArray[] = {2,4};
    int sum = 3;
    cout << boolalpha << subArraywithGivenSum(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]),sum);

    return 0;
}