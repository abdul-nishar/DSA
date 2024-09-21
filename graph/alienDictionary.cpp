#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfsTraversal(int node, vector<int>& visited, vector<vector<int>> adjList, string& result){
    visited[node] = 1;
    
    for(auto val : adjList[node]){
        if(!visited[val]) dfsTraversal(val, visited, adjList, result);
    }
    
    result += char('a' + node);
}

string topoSort(int V, vector<vector<int>> adjList) {
    string result;
    vector<int> visited(V,0);
    
    for(int i=0;i<V;i++){
        if(!visited[i]) dfsTraversal(i, visited, adjList, result);
    }
    
    reverse(result.begin(),result.end());
    
    return result;
}

string findOrder(string dict[], int n, int k) {
    vector<vector<int>> adjList(k);
    
    for(int i=0;i<n-1;i++){
        int len = min(dict[i].length(), dict[i+1].length());
        int j = 0;
        
        while(j < len && dict[i][j] == dict[i+1][j]) j++;
        
        if(j < len) {
            adjList[dict[i][j] - 'a'].push_back(dict[i+1][j] - 'a');
        }else if(dict[i].length() > dict[i + 1].length()) {
            return "";
        }
    }

    return topoSort(k, adjList);
}