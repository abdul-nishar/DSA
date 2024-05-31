#include <iostream>
#include <vector>

using namespace std;

int factorial(int n){
    int product = 1;
    for(int i=1;i<=n;i++) product*=i;
    return product;
}

// vector<int> missingRepeating(int arr[], int n) {
//     int product = factorial(n);
//     int P=1,S=0;
//     for(int i=0;i<n;i++) {
//         P*=arr[i];
//         S+=arr[i];
//     }
//     int missingNum = (product*((n*(n+1))-(2*S)))/(2*(product-P));
//     int repeatingNum = missingNum * P / product;
//     return {repeatingNum, missingNum};
// }

vector<int> missingRepeating(int arr[], int n) {
	int repeatingNum, missingNum;
	
	for(int i=0;i<n;i++){
		if(arr[abs(arr[i])-1]<0){
			repeatingNum=abs(arr[i]);
		}
		arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
	}
	
	for(int i=0;i<n;i++){
		if(arr[i]>0) missingNum = i+1;
	}
	
	return {repeatingNum, missingNum};
}

int main(){
    int numbersArray[] = {5,7,2,1,2,4,3};
    vector<int> result;
    result = missingRepeating(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]));
    for(auto value : result) cout << value << " ";
    return 0;
}