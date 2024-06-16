#include <iostream>
#include <vector>
using namespace std;

void zigZagArr(vector<int> &arr) {
    bool flag = true;
    for(int i=0;i<arr.size()-1;i++){
        if(flag){
            if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
        }else {
            if(arr[i]<arr[i+1]) swap(arr[i],arr[i+1]);
        }
        flag = !flag;
    }
}

int main(){
    vector<int> arr1 = {4, 3, 7, 8, 6, 2, 1};
    zigZagArr(arr1);
    for(int i=0;i<arr1.size();i++) cout << arr1[i] << " ";
    return 0;
}