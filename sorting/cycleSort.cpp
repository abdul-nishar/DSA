#include <iostream>
using namespace std;

int cycleSort(int arr[], int n) {
    int writes = 0;

    for (int cycleStart = 0; cycleStart < n - 1; cycleStart++) {
        int item = arr[cycleStart];

        int pos = cycleStart;
        for (int i = cycleStart + 1; i < n; i++) {
            if (arr[i] < item)
                pos++;
        }

        if (pos == cycleStart)
            continue;

        while (item == arr[pos])
            pos++;

        if (pos != cycleStart) {
            swap(item, arr[pos]);
            writes++;
        }

        while (pos != cycleStart) {
            pos = cycleStart;
            for (int i = cycleStart + 1; i < n; i++) {
                if (arr[i] < item)
                    pos++;
            }

            while (item == arr[pos])
                pos++;

            if (item != arr[pos]) {
                swap(item, arr[pos]);
            }
        }
    }
    return writes;
}

int main(){
    int numbersArray[] = {7,6,5,3,1};
    int numberOfSwaps = cycleSort(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    cout << numberOfSwaps <<endl;
    for(int i=0;i<sizeof(numbersArray)/sizeof(numbersArray[0]);i++) cout << numbersArray[i] << " "
;    return 0;
}