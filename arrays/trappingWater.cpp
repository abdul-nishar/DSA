#include <iostream>

using namespace std;

long long trappingWater(int arr[], int n){
        int lmax[n], rmax[n];
        
        lmax[0] = arr[0];
        for(int i=1;i<n;i++){
            lmax[i] = max(arr[i],lmax[i-1]);
        }
        
        rmax[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            rmax[i] = max(arr[i],rmax[i+1]);
        }
        
        long long trappedWater = 0;
        for(int i=1;i<n-1;i++){
            trappedWater += min(lmax[i],rmax[i]) - arr[i];
        }
        
        return trappedWater;
    }

int main(){
    int numbersArray[] = {3,0,0,2,0,4};
    cout << trappingWater(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
}