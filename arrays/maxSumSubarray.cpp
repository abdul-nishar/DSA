#include <iostream>

using namespace std;

int maxSumSubArray(int arr[],int n){
	long long res = arr[0];
	long long curMax = 0;

	for(int i=0;i<n;i++){
		curMax = max(curMax+arr[i],(long long)arr[i]);
		res = max(curMax,res);
	}
    
    return res;
}

int main() {
    int numbersArray[]= {-3,8,-2,4,-5,6};
    cout << maxSumSubArray(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    return 0;
}