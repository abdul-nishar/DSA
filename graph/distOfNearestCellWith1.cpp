#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> nearest(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> ans(n,vector<int>(m,0));
    vector<vector<int>> visited(n,vector<int>(m,0));
    
    queue<pair<pair<int,int>,int>> q;
    
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(grid[row][col]==1) {
                q.push({{row,col},0});
                visited[row][col] = 1;
            }
        }
    }
    
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        
        q.pop();
        
        ans[row][col] = dist;
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        
        for(int i=0;i<4;i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            
            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol]) {
                q.push({{nrow,ncol}, dist + 1});
                visited[nrow][ncol] = 1;
            }
        }
        
    }
    
    return ans;
}