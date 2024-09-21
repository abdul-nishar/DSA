#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
    vector<int> adj[N];
    
    for(auto course : prerequisites){
        adj[course.first].push_back(course.second);
    }
    
    vector<int> indegree(N,0);
    
    for(int i=0;i<P;i++){
        indegree[prerequisites[i].second]++;
    }
    
    queue<int> q;
    
    for(int i=0;i<N;i++){
        if(indegree[i] == 0) q.push(i);
    }
    
    int count = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        count++;
        
        for(auto val : adj[node]){
            indegree[val]--;
            if(indegree[val] == 0) q.push(val);
        }
    }
    
    return count == N;
}