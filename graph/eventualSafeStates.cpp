#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool cycleCheck(vector<int> adj[], vector<int>& visited, vector<int>& pathVis, vector<int>& check, int node){
    visited[node] = 1;
    pathVis[node] = 1;
    
    for(auto val : adj[node]){
        if(!visited[val]) {
            if(cycleCheck(adj, visited, pathVis, check, val)) return true;
        }else if(pathVis[val]) return true;
    }
    
    
    check[node] = 1;
    pathVis[node] = 0;
    
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int> visited(V,0);
    vector<int> pathVis(V,0);
    vector<int> check(V,0);
    
    vector<int> result;
    
    for(int i=0;i<V;i++){
        if(!visited[i]) cycleCheck(adj, visited, pathVis, check, i);
    }
    
    for(int i=0;i<V;i++) if(check[i]) result.push_back(i);
    
    return result;
}
    
    // Topological Sorting (BFS)
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> newAdj[V];
        vector<int> indegree(V,0);
        
        for(int i=0;i<V;i++){
            for(auto val : adj[i]){
                newAdj[val].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<V;i++) if(indegree[i] == 0) q.push(i);
        
        vector<int> result;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            result.push_back(node);
            
            for(auto val : newAdj[node]){
                indegree[val]--;
                if(indegree[val] == 0) q.push(val);
            }
        }
        
        sort(result.begin(),result.end());
        
        return result;
    }