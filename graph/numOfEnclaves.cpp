#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void findLands(vector<vector<int>>& visited, vector<vector<int>>& grid, int& count, int row, int col){
    queue<pair<int,int>> q;
    q.push({row,col});
    
    int n = grid.size();
    int m = grid[0].size();
    
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,-1,0,1};
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        
        q.pop();
        
        // Need this so that count does not go below 0
        if (visited[row][col]) continue;
        
        count--;
        visited[row][col] = 1;
        
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol]){
                q.push({nrow,ncol});
            }
        }
    }
}

int numberOfEnclaves(vector<vector<int>> &grid) {
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    
    
    vector<vector<int>> visited(n, vector<int>(m,0));
    
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(grid[row][col]) count++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (grid[i][0] && !visited[i][0]) findLands(visited, grid, count, i, 0);
        if (grid[i][m - 1] && !visited[i][m-1]) findLands(visited, grid, count, i, m-1);
    }
    
    for (int j = 0; j < m; j++) {
        if (grid[0][j] && !visited[0][j]) findLands(visited, grid, count, 0, j);
        if (grid[n - 1][j] && !visited[n-1][j]) findLands(visited, grid, count, n-1, j);
    }
    
    return count;
}