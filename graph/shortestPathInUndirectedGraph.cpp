#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    vector<int> result(N,-1);
    vector<vector<int>> adjList(N);
    
    for(int i=0;i<M;i++){
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    
    vector<int> visited(N,0);
    
    queue<pair<int,int>> q;
    
    q.push({src,0});
    
    while(!q.empty()){
        int node = q.front().first;
        int dist = q.front().second;
        
        q.pop();
        visited[node] = 1;
        if(result[node] == -1) result[node] = dist;
        
        for(auto val : adjList[node]){
            if(!visited[val]) q.push({val, dist + 1});
        }
    }
    
    return result;
}