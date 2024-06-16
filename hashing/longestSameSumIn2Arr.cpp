#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSameSumIn2Arr(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int,int> sumMap;
    int curSum = 0, maxSize = 0;
    for(int i = 0; i < arr1.size(); i++){
        curSum += arr1[i] - arr2[i];
        if(curSum == 0) maxSize = max(maxSize, i + 1);
        if(sumMap.count(curSum)) maxSize = max(maxSize, i - sumMap[curSum]);
        else sumMap[curSum] = i;
    }
    return maxSize;
}

int main(){
    vector<int> arr1 = {0,1,0,0,0,0};
    vector<int> arr2 = {1,0,1,0,0,1};
    cout << longestSameSumIn2Arr(arr1, arr2);
    return 0;
}