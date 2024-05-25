#include <iostream> 

using namespace std;

int largestElementIndex(int *array, int n) {
    int maxIndex = 0;
    for (int i = 0; i < n; i++){
        if(array[i] > array[maxIndex]) maxIndex = i;
    }

    return maxIndex;
}

int main() {
    int arrayOfNumbers[7] = {8,3,5,2,73,4,1};
    cout<<largestElementIndex(arrayOfNumbers, sizeof(arrayOfNumbers) / sizeof(int))<<endl;
}