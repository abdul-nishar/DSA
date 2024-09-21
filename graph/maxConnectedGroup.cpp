#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node) {
        if (node == parent[node]) 
            return node;
        
        parent[node] = findUltimateParent(parent[node]);
        return parent[node];
    }

    void unionBySize(int u, int v) {
        int utp_u = findUltimateParent(u);
        int utp_v = findUltimateParent(v);

        if (utp_u == utp_v) 
            return;

        if (size[utp_u] < size[utp_v]) {
            parent[utp_u] = utp_v;
            size[utp_v] += size[utp_u];
        } else {
            parent[utp_v] = utp_u;
            size[utp_u] += size[utp_v];
        }
    }

    int getSize(int node) {
        return size[findUltimateParent(node)];
    }
};

int MaxConnection(vector<vector<int>>& grid) {
    int n = grid.size();
    bool foundZero = false;
    
    DisjointSet ds(n*n);
    
    queue<pair<int,int>> q;
    
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,-1,0,1};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            if(grid[i][j] == 0) {
                foundZero = true;
                q.push({i,j});
            }
            else {
                int x = i * n + j;
                
                for(int k=0;k<4;k++){
                    int nrow = delrow[k] + i;
                    int ncol = delcol[k] + j;
                    
                    if(nrow < n && nrow >=0 && ncol < n && ncol >=0 && grid[nrow][ncol] == 1) {
                        int digit = nrow * n + ncol;
                        ds.unionBySize(digit,x);
                    }
                }
            }
        }
    }
    
    int result = 0;
    
    
    while(!q.empty()){
        unordered_set<int> uniqueParents;
        
        int row = q.front().first;
        int col = q.front().second;
        
        q.pop();
        
        int curSum = 1;
        
        for(int i=0;i<4;i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            
            int digit = nrow * n + ncol;
            
            if(nrow < n && nrow >=0 && ncol < n && ncol >=0 && grid[nrow][ncol] == 1){
                int parent = ds.findUltimateParent(digit);
                
                if(!uniqueParents.count(parent)){
                    curSum += ds.getSize(parent);
                    uniqueParents.insert(parent);
                }
            }
        }
        
        result = max(result, curSum);
    }
    
    return foundZero ? result : n*n;
}