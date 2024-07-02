#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int celebrity(vector<vector<int> >& M, int n){
    int row = 0, col = 0;
    
    while(col<n){
        if(row == n) return -1;
        if(row==col || M[row][col] == 0) col++;
        else {
            if(col <= row) row++;
            else row = col;
            col = 0;
        }
    }
    
    bool prospect = true;
    
    for(int i=0;i<n;i++){
        if(i==row) continue;
        if(M[i][row] == 0) {prospect = false;break;}
    }
    
    if(prospect) return row;
    else return -1;
}

int main(){
    vector<vector<int>> matrix = 
        {{0,1,0},
         {0,0,0}, 
         {0,1,0}};

    cout << celebrity(matrix, matrix.size());
    return 0;
}