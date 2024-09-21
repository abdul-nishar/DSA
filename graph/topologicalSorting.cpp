#include <iostream>
#include <vector>

using namespace std;

void dfsTraversal(int node, vector<int>& visited, vector<int> adj[], vector<int>& result){
    visited[node] = 1;
    
    for(auto val : adj[node]){
        if(!visited[val]) dfsTraversal(val, visited, adj, result);
    }
    
    result.push_back(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> result;
    vector<int> visited(V,0);
    
    for(int i=0;i<V;i++){
        if(!visited[i]) dfsTraversal(i, visited, adj, result);
    }
    
    reverse(result.begin(),result.end());
    
    return result;
}