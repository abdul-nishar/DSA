#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    
    if(start == end) return 0;
    
    vector<int> visited(100000, false);
    
    queue<pair<int,int>> q;
    
    q.push({0,start});
    visited[start] = true;
    
    while(!q.empty()){
        int count = q.front().first;
        int curVal = q.front().second;
        
        q.pop();
        
        for(auto multiple : arr){
            int newVal = (curVal * multiple) % 100000;
            
            if(newVal == end) return count + 1;
            
            if(!visited[newVal]){
                q.push({count + 1, newVal});
                visited[newVal] = true;
            }
        }
    }
    
    return -1;
}