#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfsTraversal(int node, vector<bool>& visited, vector<vector<int>>& adjList, stack<int>& st){
    	    
    visited[node] = true;
    
    for(auto adjNode : adjList[node]){
        if(!visited[adjNode]) dfsTraversal(adjNode, visited, adjList, st);
    }
    
    st.push(node);
}

void dfsTraversal2(int node, vector<bool>& visited, vector<vector<int>>& adjList){
    
    visited[node] = true;
    
    for(auto adjNode : adjList[node]){
        if(!visited[adjNode]) dfsTraversal2(adjNode, visited, adjList);
    }
}

int kosaraju(int V, vector<vector<int>>& adj){
    stack<int> st;
    vector<bool> visited(V,false);
    
    for(int i=0;i<V;i++) if(!visited[i]) dfsTraversal(i, visited, adj, st);
    
    vector<vector<int>> newAdjList(V);
    
    for(int i=0;i<V;i++){
        for(auto adjNode : adj[i]) newAdjList[adjNode].push_back(i);
    }
    
    int count = 0;
    fill(visited.begin(), visited.end(), false);
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        
        if(!visited[node]) {
            count++;
            dfsTraversal2(node, visited, newAdjList);
        }
    }
    
    return count;
}