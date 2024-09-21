#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
    
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    
    vector<vector<int>> minEffort(rows, vector<int>(columns, INT_MAX));
    
    pq.push({0,{0,0}});
    minEffort[0][0] = 0;
    
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,-1,0,1};
    
    while(!pq.empty()){
        int curEffort = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        
        pq.pop();
        
        if(row == rows - 1 && col == columns - 1) return curEffort;
        
        for(int i=0;i<4;i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            
            if(nrow < rows && nrow >= 0 && ncol < columns && ncol >= 0){
                int nextEffort = max(curEffort, abs(heights[row][col] - heights[nrow][ncol]));
                
                if (nextEffort < minEffort[nrow][ncol]) {
                    minEffort[nrow][ncol] = nextEffort;
                    pq.push({nextEffort, {nrow, ncol}});
                }
            }
        }
    }
    
    return -1;
}