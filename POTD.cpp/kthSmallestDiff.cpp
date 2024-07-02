#include <iostream>
#include <map>

using namespace std;

int countPairs(int a[], int n, int mid){
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += upper_bound(a + i, a + n, a[i] + mid) - (a + i + 1);
    }
    return res;
}

int kthSmallestDiff(int a[], int n, int k) 
{ 
    sort(a, a + n);

    int low = a[1] - a[0];
    for (int i = 1; i <= n - 2; ++i) {
        low = min(low, a[i + 1] - a[i]);
    }
    int high = a[n - 1] - a[0];

    while (low < high) {
        int mid = (low + high) >> 1;
        if (countPairs(a, n, mid) < k)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
} 

int main(){
    int numArr[] = {1,1,2,3,4,5,4,9,5};
    cout << kthSmallestDiff(numArr, 9, 5);
    return 0;
}