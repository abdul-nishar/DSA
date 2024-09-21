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

int maxRemove(vector<vector<int>>& stones, int n) {
    int maxIndex = 20000;
    
    DisjointSet ds(maxIndex);
    
    for(auto coordinates : stones){
        int row = coordinates[0];
        int col = coordinates[1];
        
        ds.unionBySize(row, col + 10000);
    }
    
    unordered_set<int> uniqueParents;
    
    for(auto coordinates : stones){
        int row = coordinates[0];
        uniqueParents.insert(ds.findUltimateParent(row));
    }
    
    return n - uniqueParents.size();
}