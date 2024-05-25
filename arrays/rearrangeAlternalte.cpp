#include <iostream>

using namespace std;

void rearrange(long long *arr, int n) 
    { 
    	for(int i=0;i<n;i+=2){
    	   swap(arr[i],arr[n-1]);
    	   swap(arr[n-1],arr[n-2-i/2]);
    	   swap(arr[n-2-i/2],arr[i+1]);
    	}
    }

int main(){
    long long numbersArray[] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160};
    rearrange(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    for(int i=0;i<16;i++){
        cout<<numbersArray[i]<<" ";
    }
}