#include <iostream>
#include <vector>

using namespace std;

void DFSTraversal(int node, vector<int> adjLs[], vector<int>& visited){
    visited[node] = 1;
    for(auto it : adjLs[node]){
        if(!visited[it]) DFSTraversal(it, adjLs, visited);
    }
}

int numProvinces(vector<vector<int>> adj, int V) {
    vector<int> adjLs[V];
    
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j] == 1 && i != j){
                 adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    
    vector<int> visited(V,0);
    int count = 0;
    
    for(int i=0;i<V;i++){
        if(!visited[i]) {
            count++;
            DFSTraversal(i, adjLs, visited);
        }
    }
    
    return count;
}