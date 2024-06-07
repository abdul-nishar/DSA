#include <iostream>
using namespace std;

void hoarePartition(int arr[], int n, int p) {
    swap(arr[0], arr[p]);
    int pivot = arr[0];
    int p1=1,p2=n-1;
    while(p1<p2){
        while(arr[p1]<pivot) p1++;
        while(arr[p2]>pivot) p2--;
        if(p1>p2) break;
        swap(arr[p1++],arr[p2--]);
    }
    swap(arr[0],arr[p2]);
    cout << "p1 : " << p1 << " p2 : " << p2 << endl;
}



int main(){
    int numbersArray[] = {9,10};
    hoarePartition(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]), 1);
    for(int i=0; i<2;i++) cout << numbersArray[i] << " ";
    return 0;
}