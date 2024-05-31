#include <iostream>
#include <unordered_map>
using namespace std;

int countOccurence(int arr[], int n, int x){
    unordered_map<int, int> frequency;
    
    for(int i=0;i<n;i++) frequency[arr[i]]++;
    
    int count=0;
    
    for(auto value : frequency) if(value.second>n/x) count++;
    
    return count;
}

int main(){
    int numbersArray[] = {3,1,2,2,1,2,3,3};
    cout << countOccurence(numbersArray,sizeof(numbersArray)/sizeof(numbersArray[0]), 3);
    return 0;
}