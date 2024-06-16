#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubArrWithEqual1sAnd0s(vector<int>& A) {
    unordered_map<int,int> binaryMap;
    for(int i = 0; i < A.size();i++){
        if(A[i]==0) A[i] = -1;
    }

    int curSum = 0, maxSize = 0;
    for(int i=0;i<A.size();i++){
        curSum += A[i];

        if(curSum == 0) maxSize = max(maxSize, i + 1);

        if(binaryMap.count(curSum)) maxSize = max(maxSize, i - binaryMap[curSum]);
        else binaryMap[curSum] = i;
    }

    return maxSize;
}

int main(){
    vector<int> arr1 = {1,1,1,1};
    cout << longestSubArrWithEqual1sAnd0s(arr1);
    return 0;
}