#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dijkstraAlgorithm(int src, int n, vector<vector<pair<int,int>>> adjList, int threshold){
    vector<int> distances(n,INT_MAX);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    distances[src] = 0;
    
    pq.push({0,src});
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        
        pq.pop();
        
        for(auto pair : adjList[node]){
            int adjNode = pair.first;
            int curDist = pair.second;
            
            if(curDist + dist < distances[adjNode]){
                distances[adjNode] = curDist + dist;
                pq.push({curDist + dist, adjNode});
            }
        }
    }
    
    int count = -1;
    
    for(int i=0;i<n;i++){
        if(distances[i] <= threshold) count++;
    }
    
    return count;
}

int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
    vector<int> result(n,0);
    
    vector<vector<pair<int,int>>> adjList(n);
    
    for(int i=0;i<m;i++){
        adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adjList[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    
    int answer = 0;
    
    for(int i=0;i<n;i++){
        result[i] = dijkstraAlgorithm(i, n, adjList, distanceThreshold);
        if(result[i] <= result[answer]) answer = i;
    }
    
    return answer;
}