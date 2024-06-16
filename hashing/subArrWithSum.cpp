#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool subArrWithSum(vector<int>& A, int sum) {
    unordered_set<int> sumSet;
    int curSum = 0;
    for(int i = 0; i < A.size();i++){
        curSum += A[i];
        if(sumSet.count(curSum-sum)) return true;
        else sumSet.insert(curSum);
    }

    return false;
}

int main(){
    vector<int> arr1 = {10,2,-2,-20,10};
    cout << subArrWithSum(arr1,-10);
    return 0;
}