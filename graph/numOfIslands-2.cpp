#include <iostream>
#include <vector>
#include <unordered_set>

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

    void unionByRank(int u, int v) {
        int utp_u = findUltimateParent(u);
        int utp_v = findUltimateParent(v);

        if (utp_u == utp_v) 
            return;

        if (rank[utp_u] < rank[utp_v])
            parent[utp_u] = utp_v;
        else if (rank[utp_u] > rank[utp_v])
            parent[utp_v] = utp_u;
        else {
            parent[utp_u] = utp_v;
            rank[utp_v]++;
        }
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
};

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    DisjointSet ds(n*m);
    unordered_set<int> u_set;
    
    vector<int> result;
    
    int count = 0;
    
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,-1,0,1};
    
    for(auto pair : operators){
        int row = pair[0];
        int col = pair[1];
        
        int x = row * m + col;
        
        if(u_set.count(x)) {
            result.push_back(count);
            continue;
        }
        
        u_set.insert(x);
        
        count++;
        
        for(int i=0;i<4;i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            
            if(nrow < n && nrow >=0 && ncol < m && ncol >=0){
                int digit = nrow * m + ncol;
                
                if(u_set.count(digit)) {
                    if(ds.findUltimateParent(x) != ds.findUltimateParent(digit)) {
                        count--;
                        ds.unionBySize(x,digit);
                    }
                }
            }
        }
        
        result.push_back(count);
    }
    
    return result;
}

int main(){
    
}