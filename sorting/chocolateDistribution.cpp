#include <iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int p = random() % (high - low + 1) + low;
    swap(arr[p], arr[low]);
    int pivot = arr[low];
    int p1 = low + 1, p2 = high;
    while(p1<=p2){
        while(arr[p1]<=pivot) p1++;
        while(arr[p2]>pivot) p2--;
        if(p1>p2) break;
        swap(arr[p1++], arr[p2--]);
    }
    swap(arr[p2], arr[low]);

    return p2;
}

void quickSort(int arr[], int low, int high){
    begin: 
        {
            if(low<high){
                int pivot = partition(arr, low, high);
                quickSort(arr, low, pivot-1);
                quickSort(arr, pivot+1, high);
                low = pivot + 1;
                goto begin;
            }
        }
}

int chocolateDistribution(int arr[], int n, int m) {
        quickSort(arr, 0, n-1);
        int result = INT_MAX;
        for(int i=0;i<n-(m-1);i++) {
            int diff = arr[i+m-1] - arr[i];
            result = (result > diff) ? diff : result;
        }
    return result;
}

int main(){
    int numbersArray[] = {7,3,1,8,9,12,56};
    cout << chocolateDistribution(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]), 3);
    return 0;
}