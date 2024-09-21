#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
    vector<vector<char>> ans(n, vector<char>(m,'X'));
    
    queue<pair<int,int>> q;
    
    int row = 0, col = 0;
    
    for(;row<n-1;row++) if(mat[row][0] == 'O') q.push({row,0});
    
    for(;col<m-1;col++) if(mat[n-1][col] == 'O') q.push({n-1,col});
    
    for(;row>0;row--) if(mat[row][m-1] == 'O') q.push({row,m-1});
    
    for(;col>0;col--) if(mat[0][col] == 'O') q.push({0,col});
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        
        q.pop();
        
        ans[row][col] = 'O';
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] != 'O' && mat[nrow][ncol] == 'O'){
                q.push({nrow,ncol});
            }
        }
    }
    
    return ans;
}

