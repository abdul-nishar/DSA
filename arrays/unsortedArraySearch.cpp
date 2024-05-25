#include <iostream>

using namespace std;

int unsortedArraySearch(int arr[], int n, int num){
    for (int i = 0;i < n ;i++) {
        if(arr[i] == num) return i;
    }
    return -1;
}

int main() {
    int arrayOfNumbers[] = { 5,35,6,3,526,2,43,234,6,7,13,4,32,4242 };
    cout<<unsortedArraySearch(arrayOfNumbers, sizeof(arrayOfNumbers),43);

    return 0;
}