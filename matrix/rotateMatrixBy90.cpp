#include <iostream>
#include <vector>
using namespace std;

void rotateMatrixBy90(vector<vector<int>>& matrix, int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(matrix[i][j],matrix[i][n-1-j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i==j) continue;
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}

int main(){
    vector<vector <int>> arr1 = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    rotateMatrixBy90(arr1, arr1.size());

    for(int i = 0; i < arr1.size();i++){
        for(int j = 0; j < arr1[i].size();j++) cout << arr1[i][j] << " ";
        cout << endl;
    }
    return 0;
}