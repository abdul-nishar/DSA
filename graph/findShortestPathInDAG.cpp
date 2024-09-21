#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void dfsTraversal(vector<int>& visited, vector<vector<pair<int,int>>> adjList, int node, stack<int>& s){
    visited[node] = 1;
    
    for(auto val : adjList[node]){
        if(!visited[val.first]) dfsTraversal(visited, adjList, val.first, s);
    }
    
    s.push(node);
}

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    vector<int> result(N,INT_MAX);
    vector<vector<pair<int,int>>> adjList(N);
    
    for(int i=0;i<M;i++){
        adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    
    stack<int> s;
    vector<int> visited(N,0);
    
    for(int i=0;i<N;i++){
       if(!visited[i]) dfsTraversal(visited, adjList, i, s); 
    }
    
    result[0] = 0;
    
    while(!s.empty()){
        int node = s.top();
        s.pop();
        
        if(result[node] != INT_MAX){
            for(auto val : adjList[node]){
                if(result[node] + val.second < result[val.first]) {
                    result[val.first] = result[node] + val.second;
                }
            }
        }
    }
    
    for(int i=0;i<N;i++){
        if(result[i] == INT_MAX) result[i] = -1;
    }
    
    return result;
}