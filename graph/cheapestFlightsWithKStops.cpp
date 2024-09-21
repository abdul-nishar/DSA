#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
    vector<vector<pair<int,int>>> adjList(n);
    
    vector<int> priceChart(n, INT_MAX);
    
    priceChart[src] = 0;
    
    for(int i=0;i<flights.size();i++){
        int from = flights[i][0];
        int to = flights[i][1];
        int price = flights[i][2];
        
        adjList[from].push_back({to,price});
    }
    
    queue<pair<int,pair<int,int>>> pq;
    
    pq.push({0,{src, 0}});
    
    while(!pq.empty()){
        int stops = pq.front().first;
        int city = pq.front().second.first;
        int price = pq.front().second.second;
        
        pq.pop();
        
        if (stops > K) continue;
        
        for(auto pair : adjList[city]){
            int destination = pair.first;
            int p = pair.second;
            
            if(price + p < priceChart[destination] && stops <= K) {
                priceChart[destination] = price + p;
                pq.push({stops + 1,{destination,price + p}});
            }
        }
    }
    
    if(priceChart[dst] == INT_MAX) return -1;
    else return priceChart[dst];
}