#include <iostream>

using namespace std;

int maxConsecutiveOnes(int arr[], int n){
    int maxValue =0;
    int temp = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==1) temp++;
        else if(arr[i]==0) {
            if(maxValue<temp) maxValue = temp;
            temp = 0;
        }
    }

    return maxValue;
}

int main() {
    int binaryArray[] = {0,1,1,0,1,0};
    cout << maxConsecutiveOnes(binaryArray, sizeof(binaryArray)/sizeof(binaryArray[0]));
    return 0;
}