#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// UNDIRECTED GRAPH

bool detect(vector<int> adj[], vector<int>& visited, int src){
    queue<pair<int,int>> q;
    q.push({src,-1});
    visited[src] = 1;
    
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                visited[neighbour] = 1;
                q.push({neighbour,node});
            }else if(parent != neighbour) return true;
        }
    }
    
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) if(detect(adj,visited,i)) return true;
    }
    
    return false;
}

// DIRECTED GRAPH

bool dfsTraversal(vector<int>& visited, vector<int>& pathVis, vector<int> adj[], int node){
    visited[node] = 1;
    pathVis[node] = 1;
    
    for(auto val : adj[node]){
        if(!visited[val]) {
            if(dfsTraversal(visited, pathVis, adj, val)) return true;
        }
        else if(pathVis[val]) return true;
    }
    
    pathVis[node] = 0;
    
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> visited(V,0);
    vector<int> pathVis(V,0);
    
    for(int i=0;i<V;i++){
        if(!visited[i]) if(dfsTraversal(visited, pathVis, adj, i)) return true;
    }
    
    return false;
}