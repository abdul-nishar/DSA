#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubArrWithSum(vector<int>& A, int sum) {
    unordered_map<int,int> sumMap;
    int maxSize = 0, curSum = 0;
    for(int i = 0; i < A.size();i++){
        curSum += A[i];
        if(curSum == sum) maxSize = max(maxSize, i + 1);

        if(sumMap.count(curSum-sum)) maxSize = max(maxSize, i - sumMap[curSum-sum]);
        if(!sumMap.count(curSum))sumMap[curSum] = i;
    }
    return maxSize;
}

int main(){
    vector<int> arr1 = {3,1,0,1,8,2,3,6};
    cout << longestSubArrWithSum(arr1, 5);
    return 0;
}