#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;

public:
    int count;
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n, 1);
        count = 0;

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
            count++;

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
            count++;

        if (size[utp_u] < size[utp_v]) {
            parent[utp_u] = utp_v;
            size[utp_v] += size[utp_u];
        } else {
            parent[utp_v] = utp_u;
            size[utp_u] += size[utp_v];
        }
    }
};

int Solve(int n, vector<vector<int>>& edge) {
    DisjointSet ds(n);
    
    for(int i=0;i<edge.size();i++) ds.unionBySize(edge[i][0],edge[i][1]);
    
    int count = 0;
    
    for(int i=0;i<n;i++) if(ds.findUltimateParent(i) == i) count++;
    
    return ds.count >= count - 1 ? count - 1 : -1;
}

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) 
        cout << "They have the same parent" << endl;
    else 
        cout << "They have different parents" << endl;

    ds.unionByRank(3,7);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) 
        cout << "They have the same parent" << endl;
    else 
        cout << "They have different parents" << endl;
}