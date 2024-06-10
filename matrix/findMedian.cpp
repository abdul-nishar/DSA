#include <iostream>
#include <vector>
using namespace std;

int findMedian(vector<vector<int> >& A) {
    int minVal = A[0][0], maxVal = A[0][A[0].size()-1];

    for(int i = 1; i < A.size(); i++) {
        minVal = min(minVal, A[i][0]);
        maxVal = max(maxVal, A[i][A[i].size()-1]);
    }

    int medianPos = (A.size() * A[0].size() + 1) / 2;


    while(minVal < maxVal){

        int mid = (minVal + maxVal) / 2;
        int count = 0;
        for(int i = 0; i < A.size(); i++){
            count += upper_bound(A[i].begin(),A[i].end(),mid) - A[i].begin();
            cout << count << endl;
        }
        if(count >= medianPos) maxVal = mid;
        else minVal = mid + 1;
    }

    return minVal;
}

int main(){
    vector<vector <int>> arr1 = {{5,10,20,30,40},{1,2,3,4,6},{11,13,15,17,19}};
    cout << findMedian(arr1);
    return 0;
}