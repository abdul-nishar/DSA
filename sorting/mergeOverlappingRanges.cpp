#include <iostream>
#include <vector>
using namespace std;

class MyClass {
  public:
    int left;
    int right;

    MyClass(int left, int right) {
      this->left = left;
      this->right = right;
    }
};

int hoarePartition( MyClass arr[], int low, int high){
    int p = rand() % (high - low + 1) + low;
    swap(arr[p].left,arr[low].left);
    swap(arr[p].right,arr[low].right);
    int pivot = arr[low].left;
    int p1 = low+1, p2 = high;
    while(p1<=p2){
        while(arr[p1].left<pivot) p1++;
        while(arr[p2].left>pivot) p2--;
        if(p1>p2) break;
        swap(arr[p1].left,arr[p2].left);
        swap(arr[p1].right,arr[p2].right);
        p1++;p2--;
    }

    swap(arr[low].left, arr[p2].left);
    swap(arr[low].right, arr[p2].right);
    return p2;
}

void quickSort(MyClass arr[], int low, int high){ 
    begin:   
        if(low<high){
            int pivot = hoarePartition(arr, low, high);
            quickSort(arr, low, pivot-1);
            quickSort(arr, pivot+1, high);
            low=pivot+1;
            goto begin; // required for tail-call elimination
        }
}

void mergeOverlappingRanges(MyClass arr[], int n) {
    quickSort(arr, 0, n-1);
    int arrSize = n;
    for(int i = n-1; i > 0; i--){
        if((arr[i].left < arr[i-1].left && arr[i].right < arr[i-1].left) || (arr[i].left > arr[i-1].right && arr[i].right > arr[i-1].right))cout << "{" << arr[i].left << "," << arr[i].right << "}" << endl;
        else{
            arr[i-1].left = min(arr[i].left, arr[i-1].left);
            arr[i-1].right = max(arr[i].right, arr[i-1].right);

            arrSize--;
        }
    }

    cout << "{" << arr[0].left << "," << arr[0].right << "}" << endl;
}

int main(){
    MyClass numbersArray[] = {MyClass(1,3),MyClass(2,4),MyClass(5,7), MyClass(6,8)};
    mergeOverlappingRanges(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));

    return 0;
}