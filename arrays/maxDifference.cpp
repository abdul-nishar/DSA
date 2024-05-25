#include <iostream>
#include <algorithm>

using namespace std;

int maxDiff(int a[], int n){
    int maxValue  = a[n-1], result = 0;
    for(int i = n-2; i>=0;i--){
        if(a[i] > maxValue) maxValue = a[i];
        else result = max(result, maxValue-a[i]);
    }

    return result;
}

int main() {
    int numbersArray[] = {34,8,10,3,2,80,30,33,1};
    cout<<maxDiff(numbersArray,9); 
    return 0;
}