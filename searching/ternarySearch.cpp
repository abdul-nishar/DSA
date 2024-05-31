#include <iostream>
using namespace std;

int ternarySearch(int arr[], int element, int left, int right) {
    int mid1 = left + (right-left)/3;
    int mid2 = right - (right-left)/3;
    while(left<=right){
        if(arr[mid1]==element) return mid1;
        else if(arr[mid2]==element) return mid2;
        else if(arr[mid1]>element) right = mid1-1;
        else if(arr[mid2]<element) left = mid2+1;
        else {
            left=mid1+1;
            right=mid2-1;
        }
    }

    return -1;
}

int main(){
    int numbersArray[] = {10,20,30,40,50,60,70};
    cout << ternarySearch(numbersArray, 50, 0, sizeof(numbersArray)/sizeof(numbersArray[0])-1);
    return 0;
}