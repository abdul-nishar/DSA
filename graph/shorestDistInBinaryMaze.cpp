#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> distances(n, vector<int>(m, INT_MAX));
    
    distances[source.first][source.second] = 0;
    
    queue<pair<int,pair<int,int>>> q;
    
    q.push({0, source});
    
    while(!q.empty()){
        int dist = q.front().first;
        auto point = q.front().second;
        
        q.pop();
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        
        for(int i=0;i<4;i++){
            int nrow = delrow[i] + point.first;
            int ncol = delcol[i] + point.second;
            
            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && grid[nrow][ncol] == 1){
                if(distances[nrow][ncol] > dist + 1){
                    distances[nrow][ncol] = dist + 1;
                    q.push({dist + 1, {nrow,ncol}});
                }
            }
        }
    }
    
    if(distances[destination.first][destination.second] == INT_MAX) return -1;
    
    return distances[destination.first][destination.second];
}