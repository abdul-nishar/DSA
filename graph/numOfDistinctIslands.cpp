#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfsTraversal(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid, vector<pair<int,int>>& vec, int row0, int col0){
    int n = grid.size();
    int m = grid[0].size();
    
    visited[row][col] = 1;
    vec.push_back({row0 - row, col0 - col});
    
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,-1,0,1};
    
    for(int i=0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        
        if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol] && grid[nrow][ncol]){
          dfsTraversal(nrow,ncol,visited,grid,vec,row0,col0);  
        }
    }
}

int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> visited(n,vector<int>(m,0));
    set<vector<pair<int,int>>> nodeSet;
    
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(!visited[row][col] && grid[row][col]){
                vector<pair<int,int>> vec;
                dfsTraversal(row,col,visited,grid,vec,row,col);
                nodeSet.insert(vec);
            }
        }
    }
    
    return nodeSet.size();
}