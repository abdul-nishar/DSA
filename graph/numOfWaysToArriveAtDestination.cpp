#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
        
    int modulo = (int)(1e9 + 7);
    vector<vector<pair<int,long long>>> adjList(n);
    
    for(int i=0;i<roads.size();i++){
        int from = roads[i][0];
        int to = roads[i][1];
        long long timeTaken = roads[i][2];
        
        adjList[from].push_back({to,timeTaken});
        adjList[to].push_back({from,timeTaken});
    }
    
    vector<long long> minTime(n, LONG_MAX);
    vector<int> pathCount(n, 0);
    
    minTime[0] = 0;
    pathCount[0] = 1;
    
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    
    pq.push({0,0});
    
    while(!pq.empty()){
        long long curTime = pq.top().first;
        int curNode = pq.top().second;
        
        pq.pop();
        
        for(auto node : adjList[curNode]){
            int adjNode = node.first;
            long long newTime = node.second;
            
            if(curTime + newTime < minTime[adjNode]){
                minTime[adjNode] = curTime + newTime;
                pathCount[adjNode] = pathCount[curNode];
                pq.push({curTime + newTime, adjNode});
            }else if(curTime + newTime == minTime[adjNode]) {
                pathCount[adjNode] = (pathCount[adjNode] + pathCount[curNode]) % modulo;
            }
        }
    }
    
    return pathCount[n-1] % modulo;
}