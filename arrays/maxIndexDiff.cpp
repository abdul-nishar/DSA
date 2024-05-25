#include <iostream>

using namespace std;

int maxIndexDiff(int a[], int n){
    int mn[n],mx[n];

    mn[0] = a[0];
    for (int i = 1; i < n; i++){
        mn[i] = min(mn[i-1], a[i]);
    }

    mx[n-1] = a[n-1];
    for (int j = n-2; j >= 0; j--){
        mx[j] = max(mx[j+1], a[j]);
    }

    int x=0,y=0,ans=-1;
    while(x<n && y<n){
        if(mn[x] <= mx[y]){
            ans = max(ans, y-x);
            y++;
        } else x++;
    }
    return ans;
}

int main() {
    int numbersArray[] = {34,8,10,3,2,80,30,33,1};
    cout<<maxIndexDiff(numbersArray,9); 
    return 0;
}