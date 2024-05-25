#include <iostream>

using namespace std; 

void minConsecutiveFlips(int arr[], int n){
    int flipValue = arr[0] + 1 % 2;

    for(int i = 1; i < n; i++) {
        if(arr[i] == flipValue && arr[i-1]!=flipValue) cout << "From " << i << " ";
        if(arr[i] == flipValue && arr[i+1]!=flipValue && i < n) cout << "To " << i << endl;
    }
}

int main() {
    int binaryArr[] = {0,0,1,1,0,0,1,1,0,1};
    minConsecutiveFlips(binaryArr, sizeof(binaryArr)/sizeof(binaryArr[0]));
    return 0;
}

