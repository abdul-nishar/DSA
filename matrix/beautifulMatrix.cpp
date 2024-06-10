#include <iostream>
#include <vector>
using namespace std;

int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> rows;
        vector<int> cols;
        
        for(int i=0;i<n;i++){
            int rowSum = 0;
            for(int j=0;j<n;j++) rowSum += matrix[i][j];
            rows.push_back(rowSum);
        
            int colSum = 0;
            for(int k=0;k<n;k++) colSum += matrix[k][i];
            cols.push_back(colSum);
        }
        
        int rowMaxVal = rows[0], colMaxVal = cols[0];
        for(int i=1;i<rows.size();i++) rowMaxVal = max(rowMaxVal, rows[i]);
        for(int j=1;j<cols.size();j++) colMaxVal = max(colMaxVal, cols[j]);
        
        int result = 0;
        if(rowMaxVal > colMaxVal) {
            for(int i = 0; i<rows.size();i++) {
                result+=(rowMaxVal-rows[i]);
            }
        }else for(int j=0;j<cols.size();j++) result+=(colMaxVal-cols[j]);
        
        return result;
    } 

int main(){
    vector<vector <int>> arr1 = {{1,2},{3,4}};
    cout << findMinOpeartion(arr1, 2);
    return 0;
}