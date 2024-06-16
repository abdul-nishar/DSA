#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int zeroSumSubArrCount(vector<int>& A) {
    unordered_map<int, int> sumMap;
    int curSum = 0, count = 0;

    for(int i = 0; i < A.size();i++){
        curSum += A[i];
        if(curSum == 0)count++;

        if(sumMap.count(curSum)) count += sumMap[curSum];

        sumMap[curSum]++;
    }

    return count;
}

int main(){
    vector<int> arr1 = {6,-1,-3,4,-2,2,4,6,-12,-7};
    cout << zeroSumSubArrCount(arr1);
    return 0;
}