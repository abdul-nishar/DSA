#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS TRAVERSAL

bool isBipartite(int V, vector<int>adj[]){
    vector<int> visited(V,-1);
    queue<int> q;
    
    for(int i=0;i<V;i++){
        if(visited[i] == -1){
            q.push(i);
            visited[i] = 0;
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                        
                for(auto val : adj[node]){
                    if(visited[val] == -1) {
                        q.push(val);
                        visited[val] = !visited[node];
                    }
                    else if(visited[val] == visited[node]) return false;
                }
            }
        }
    }
    
    return true;
}

// DFS TRAVERSAL

bool dfsTraversal(int node, vector<int>& visited, vector<int> adj[], int color){
    visited[node] = color;
    
    for(auto val : adj[node]){
        if(visited[val] == -1) {
            if(!dfsTraversal(val, visited, adj, !color)) return false;
        }
        else if(visited[val] == visited[node]) return false;
    }
    
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
    vector<int> visited(V,-1);
    
    for(int i=0;i<V;i++){
        if(visited[i] == -1) 
        if(!dfsTraversal(i, visited, adj, 0)) return false;
    }
    
    return true;
}