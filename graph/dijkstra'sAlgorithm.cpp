#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// Using Priority Queue data structure
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    vector<int> result(V, INT_MAX);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0,S});
    
    result[S] = 0;
    
    while(!pq.empty()){
        int node = pq.top().second;
        int dist = pq.top().first;
        
        pq.pop();
        
        for(auto pair : adj[node]){
            if(result[pair[0]] > dist + pair[1]){
                result[pair[0]] = dist + pair[1];
                pq.push({dist + pair[1], pair[0]});
            }
        }
    }
    
    return result;
}

// Using SET data structure

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    vector<int> result(V, INT_MAX);
    
    set<pair<int,int>> st;
    
    st.insert({0,S});
    
    result[S] = 0;
    
    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dist = it.first;
        
        st.erase(it);
        
        for(auto pair : adj[node]){
            int d = pair[1];
            int n = pair[0];
            
            if(result[n] > d + dist){
                st.erase({result[n], n});
                
                result[n] = d + dist;
                
                st.insert({result[n], n});
            }
        }
    }
    
    return result;
}