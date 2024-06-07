#include <iostream>
using namespace std;

void segregateTwoElements(int arr[], int n) {
    int p1 = 0, p2 = n-1;
    while(p1<=p2){
        while(arr[p1]==0) p1++;
        while(arr[p2]==1) p2--;
        if(p1>p2) break;
        swap(arr[p1++],arr[p2--]);
    }
}

int main(){
    int numbersArray[] = {0,1,1,1,0};
    segregateTwoElements(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    for(int i =0;i<sizeof(numbersArray)/sizeof(numbersArray[0]);i++) cout << numbersArray[i] << " ";
    return 0;
}