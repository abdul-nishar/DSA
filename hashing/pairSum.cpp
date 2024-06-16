#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
bool pairSum(vector<int>& A, int sum) {
    unordered_set<int> numSet(A.begin(), A.end());
    for(auto value : numSet){
        cout << value << " : " << sum-value << endl;
        if(numSet.count(sum-value) && sum-value != value) return true;
    }

    return false;
}
*/

bool pairSum(vector<int>& A, int sum) {
    unordered_set<int> numSet;
    for(int i=0; i<A.size();i++){
        if(numSet.count(sum - A[i])) return true;
        else numSet.insert(A[i]);
    }

    return false;
}

int main(){
    vector<int> arr1 = {25,78,9,14,88,2,51, 61 ,29, 94, 85, 6 ,41 ,12 ,5 ,36 ,57 ,73 ,51};
    cout << pairSum(arr1, 24);
    return 0;
}