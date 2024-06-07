#include <iostream>
using namespace std;

/* int partition(int arr[], int low, int high, int value){
    int idx = -1;
    for(int i=low;i<=high;i++){
        if(arr[i] == value){ idx = i;break;}
    }
    
    swap(arr[low], arr[idx]);
    
    int pivot = arr[low];
    int p1 = low;
    for(int i=low+1;i<=high;i++){
        if(arr[i]<=pivot){
            p1++;
            swap(arr[p1], arr[i]);
        }
    }

    swap(arr[p1], arr[low]);

    return p1;
}   

void segregateThreeElements(int arr[], int N)
{
    if (N==1) return;
    int lowBound = 0, highBound = 2;
    int pivot1 = partition(arr, 0, N-1, lowBound);
    int pivot2 = partition(arr, pivot1+1, N-1, highBound);
} */

// Dutch National Flag Algorithm

void segregateThreeElements(int arr[], int N){
    int low = 0, mid = 0, high = N-1;
    while(mid <= high){
        if(arr[mid] == 0) swap(arr[mid++], arr[low++]);
        else if(arr[mid] == 1) mid++;
        else swap(arr[mid], arr[high--]);
    }
}

int main(){
    int numbersArray[] = {0,1,0,2,1,2};
    segregateThreeElements(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));

    for(int i=0; i<sizeof(numbersArray)/sizeof(numbersArray[0]); i++) cout << numbersArray[i] << " ";
    return 0;
}