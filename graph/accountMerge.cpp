#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

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

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    DisjointSet ds(accounts.size());
    unordered_map<string,int> u_map;
    
    for(int i=0;i<accounts.size();i++){
        for(int j=1;j<accounts[i].size();j++){
            if(u_map.count(accounts[i][j])){
                ds.unionBySize(i,u_map[accounts[i][j]]);
            }else u_map.insert({accounts[i][j], i});
        }
    }
    
    unordered_map<int, set<string>> storage;
    
    for(auto email : u_map){
        int u_parent = ds.findUltimateParent(email.second);
        
        storage[u_parent].insert(email.first);
    }
    
    vector<vector<string>> result;
    
    for(auto pair : storage){
        string person = accounts[pair.first][0];
        
        vector<string> answer;
        
        answer.push_back(person);
        
        for(auto email : pair.second) answer.push_back(email);
        
        result.push_back(answer);
    }
    
    return result;
}