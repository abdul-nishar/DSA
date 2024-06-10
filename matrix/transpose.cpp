#include <iostream>
#include <vector>
using namespace std;

void transpose(vector<vector<int> >& A) {
    for(int i = 0; i < A.size();i++){
        for(int j = i; j < A[i].size();j++){
            if(i==j) continue;
            swap(A[i][j], A[j][i]);
        }
    }
}

int main(){
    vector<vector <int>> arr1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    transpose(arr1);
    for(int i = 0; i < arr1.size();i++){
        for(int j = 0; j < arr1[i].size();j++) cout << arr1[i][j] << " ";
        cout << endl;
    }
    return 0;
}