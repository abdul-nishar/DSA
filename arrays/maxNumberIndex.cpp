#include <iostream>

using namespace std;    

int maxNumberIndex(int arr[], int n) {
    int max = arr[0];
    int maxIndex = 0;
    for (int i=1; i<n; i++){
        if (arr[i]> max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    int array1[5] = {10,20,30,40,50};
    cout <<maxNumberIndex(array1, 5);
    return 0;
}