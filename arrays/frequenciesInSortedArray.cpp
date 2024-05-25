#include <iostream>

using namespace std;

void frequencies(int arr[], int n){
    int currentEl = arr[0];
    int frequency = 0;
    for(int i=0; i<n; i++){
        if(currentEl == arr[i]) frequency++;
        else {
            cout<< to_string(currentEl) + " : " + to_string(frequency) << endl;
            currentEl = arr[i];
            frequency = 1;
        }
    }
}

int main() {
    int numbersArray[] = {10,10,10,10,20,20,30,40,40,40,40,50};
    frequencies(numbersArray, sizeof(numbersArray)/sizeof(int));
    return 0;
}