#include <iostream>
#include <vector>
using namespace std;

bool searchElement(vector<vector<int>> matrix, int n, int m, int x) 
    {
        int columnIdx = -1;
        for(int i=0;i<m;i++){
            if(matrix[0][i] == x) return true;
            else if(matrix[0][i] < x) columnIdx++;
            else break;
        }
        
        for(int i=0;i<n;i++){
            if(matrix[i][columnIdx] == x) return true;
            else if(matrix[i][columnIdx] > x) {columnIdx--;i--;}
        }
        
        return false;
    }

int main(){
    vector<vector <int>> arr1 = {{ 3, 30, 38},{36, 43, 60},{40, 51, 69}};
    int row = 3, col = 3;
    cout << searchElement(arr1, row, col, 3);
    return 0;
}