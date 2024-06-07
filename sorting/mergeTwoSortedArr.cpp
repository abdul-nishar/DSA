#include <iostream>
#include <vector>
using namespace std;

void mergeSort(int arr1[], int n, int arr2[], int m) {
    int p1=0,p2=0;

    while(p1<n && p2<m){
        if(arr2[p2]>=arr1[p1]) {
            cout << arr1[p1] << " ";
            p1++;
        }else {
            cout << arr2[p2] << " ";
            p2++;
        }
    }

    if(p1>=n) {
        while(p2==m){
        cout << arr2[p2] << " ";
        p2++;
        }
    }else if(p2==m){
        while(p1<n){
        cout << arr1[p1] << " ";
        p1++;
        }
    }

}

// Without Using Extra Space

/* int nextGap(int gap) {
        if (gap <= 1)
            return 0;
        return (gap / 2) + (gap % 2);
    }
    
void merge(long long arr1[], long long arr2[], int n, int m){ 
    int gap = n + m;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
        int i, j;
                
        for (i = 0; i + gap < n; i++) if (arr1[i] > arr1[i + gap]) swap(arr1[i], arr1[i + gap]);
        
        for (j = (gap > n ? gap - n : 0); i < n && j < m; i++, j++) if (arr1[i] > arr2[j]) swap(arr1[i], arr2[j]);
        
        if (j < m) for (j = 0; j + gap < m; j++) if (arr2[j] > arr2[j + gap]) swap(arr2[j], arr2[j + gap]);
    }
}
*/

int main(){
    int numbersArray1[] = {10,15,20};
    int numbersArray2[] = {5,6,6,15};
    int n = sizeof(numbersArray1)/sizeof(numbersArray1[0]);
    int m = sizeof(numbersArray2)/sizeof(numbersArray2[0]);
    mergeSort(numbersArray1, n, numbersArray2, m);
    return 0;
}