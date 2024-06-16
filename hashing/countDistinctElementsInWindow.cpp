#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void countDistinctElementsInWindow(vector<int>& arr, int k) {
    for(int i = 0;i<=arr.size() - k;i++){
        unordered_set<int> numSet(arr.begin()+i,arr.begin()+k+i);
        cout << numSet.size() << " ";
    }
}

int main(){
    vector<int> arr1 = {30,10,20,20,20,10,40,30,30};
    countDistinctElementsInWindow(arr1, 4);
    return 0;
}