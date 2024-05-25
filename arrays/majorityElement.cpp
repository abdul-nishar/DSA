#include <iostream>

using namespace std;

int majorityElement(int arr[], int n){
    int res = 0, count = 1;
    for(int i=1;i<n;i++){
        if(arr[res]==arr[i]) count++;
        else count--;

        if(count==0){
            res = i;
            count = 1;
        }
    }

    count = 0;
    for(int i=0;i<n;i++){
        if(arr[res]==arr[i]) count++;
    }
    if(count>n/2) return res;
    
    return -1;
}

int main(){
    int numbersArray[] = {100,2,3,100,5,100,100,101,100};
    cout << majorityElement(numbersArray,sizeof(numbersArray)/sizeof(numbersArray[0]));
    return 0;
}