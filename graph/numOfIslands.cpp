#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid){
    int n = grid.size(), m = grid[0].size();
    visited[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row, col});
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        
        q.pop();
        
        // Shortcut to traverse all the neighbours in all 8 directions
        for(int delrow = -1; delrow <= 1; delrow++){
            for(int delcol = -1; delcol <= 1; delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                    visited[nrow][col] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int count = 0;
    
    for(int row = 0; row<n; row++){
        for(int col = 0; col<m; col++){
            if(!visited[row][col] && grid[row][col] == '1'){
                count++;
                bfs(row, col, visited, grid);
            }
        }
    }
    
    return count;
}