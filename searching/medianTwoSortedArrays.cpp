#include <iostream>
#include <vector>
using namespace std;

double medianSortedArrays(int arr1[], int arr2[], int n1, int n2) {
    int low = 0, high = n1;
    int min1,min2,max1,max2;
    while(low<=high){
        int p1 = (low+high)/2;
        int p2 = (n1+n2+1)/2 - p1;

        min1 = (p1==n1) ? INT16_MAX : arr1[p1];
        min2 = (p2==n2) ? INT16_MAX :arr2[p2];

        max1 = (p1==0) ? INT16_MIN: arr1[p1-1];
        max2 = (p2==0) ? INT16_MIN: arr2[p2-1];

        if(min1>=max2 && max1<=min2) break;
        else if(min1<max2){
            low=p1+1;
        } else{
            high=p1-1;
        }
    }

    int firstValue = max(max1, max2);
    int secondValue = min(min1, min2);
    double result;

    if((n1+n2 & 1) != 1) result = (double)(firstValue+secondValue)/2;
    else result = firstValue;
    return result;
}

int main(){
    int numbersArray1[] = {1,2};
    int numbersArray2[] = {2,3,4};
    cout << medianSortedArrays(numbersArray1, numbersArray2, sizeof(numbersArray1)/sizeof(numbersArray1[0]), sizeof(numbersArray2)/sizeof(numbersArray2[0]));
    return 0;
}