#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    queue<pair<int,int>> q;
    
    int freshCount = 0;
    
    // Pushing all rotten oranges on the queue
    for(int row = 0;row<n;row++){
        for(int col = 0;col<m;col++){
            if(grid[row][col] == 2) q.push({row,col});
            else if(grid[row][col] == 1) freshCount++;
        }
    }
    
    if(freshCount == 0) return 0;
    
    q.push({-1,-1});
    
    int count = 0;
    
    while(q.size() > 1){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        if(row == -1 && col == -1) {
            count++;
            q.push({-1,-1});
            continue;
        }
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};
        
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                grid[nrow][ncol] = 2; 
                q.push({nrow, ncol});
                freshCount--;
            }
            
            if (freshCount == 0) return count + 1;
        }
    }
    
    return -1;
}