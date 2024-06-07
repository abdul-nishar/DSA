#include <iostream>
using namespace std;

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

int meetMaxGuests(int arr[], int dep[], int n) {
    quickSort(arr, 0, n-1);
    quickSort(dep, 0, n-1);
        
    int result = 1, count = 1;
    int i=1,j=0;
    while(i<n && j<n){
        if(arr[i]<=dep[j]) {count++;i++;}
        else if(arr[i]>dep[j]){count--;j++;}
        result = max(count, result);
    }
    return result > count ? result : count;
}

int main(){
    int numbersArray1[] = {800,700,600,500};
    int numbersArray2[] = {840,820,830,530};

    cout << meetMaxGuests(numbersArray1, numbersArray2, sizeof(numbersArray1)/sizeof(numbersArray1[0]));
    return 0;
}