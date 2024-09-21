#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adjList(n+1);
    
    vector<pair<int,vector<int>>> distances(n+1,{INT_MAX,vector<int>{}});
    
    distances[1] = {0,{1}};
    
    for(int i=0;i<m;i++) {
        adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adjList[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0,1});
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        
        pq.pop();
        
        if (dist > distances[node].first) continue;
        
        vector<int> path = distances[node].second;
        
        for(auto pair : adjList[node]){
            int adjNode = pair.first;
            int d = pair.second;
            
            
            if(distances[adjNode].first > d + dist) {
                distances[adjNode].first = d + dist;
                vector<int> newPath = path;
                newPath.push_back(adjNode);
                distances[adjNode].second = newPath;
                pq.push({d + dist, adjNode});
            }
        }
    }
    
    vector<int> result;
    
    if(distances[n].first == INT_MAX) return {-1};
    else {
        result.push_back(distances[n].first);
        
        for(auto node : distances[n].second) result.push_back(node);
        
        return result;
    }
}