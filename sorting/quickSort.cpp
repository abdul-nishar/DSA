#include <iostream>
#include <math.h>
using namespace std;


int lomutoPartition (int arr[], int low, int high){
    int p = random() % (high - low + 1) + low;
    swap(arr[p],arr[high]);
    int pivot = arr[high];
    int p1 = low - 1;
    for(int i = low;i < high;i++){
        if(arr[i]<=pivot) {
            p1++;
            swap(arr[i], arr[p1]);
        }
    }
    swap(arr[high],arr[p1+1]);
    return p1+1;
}

int hoarePartition(int arr[], int low, int high){
    int p = rand() % (high - low + 1) + low;
    swap(arr[p],arr[low]);
    int pivot = arr[low];
    int p1 = low+1, p2 = high;
    while(p1<=p2){
        while(arr[p1]<pivot) p1++;
        while(arr[p2]>pivot) p2--;
        if(p1>p2) break;
        swap(arr[p1++],arr[p2--]);
    }

    swap(arr[low], arr[p2]);
    return p2;
}

void quickSort(int arr[], int low, int high){ 
    begin:   
        if(low<high){
            int pivot = hoarePartition(arr, low, high);
            quickSort(arr, low, pivot-1);
            quickSort(arr, pivot+1, high);
            low=pivot+1;
            goto begin; // required for tail-call elimination
        }
}

int main(){
    int numbersArray[] = {8,4,7,9,3,10,5};
    quickSort(numbersArray, 0, sizeof(numbersArray)/sizeof(numbersArray[0])-1);
    for(int i=0;i<sizeof(numbersArray)/sizeof(numbersArray[0]);i++) cout << numbersArray[i] << " ";
    return 0;
}