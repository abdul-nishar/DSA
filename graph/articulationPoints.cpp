#include <iostream>
#include <vector>

using namespace std;

void dfsTraversal(int curNode, int parentNode, int& timer, vector<int>& initialTime, vector<int>& lowestTime, vector<bool>& markNodes, vector<int>adjList[]){
    initialTime[curNode] = lowestTime[curNode] = timer;
    timer++;
    
    int child = 0;
    
    for(auto adjNode : adjList[curNode]){
        if(parentNode == adjNode) continue;
        
        if(initialTime[adjNode] == -1){
            dfsTraversal(adjNode, curNode, timer, initialTime, lowestTime, markNodes, adjList);
            lowestTime[curNode] = min(lowestTime[curNode], lowestTime[adjNode]);
            
            if(lowestTime[adjNode] >= initialTime[curNode] && parentNode != -2) markNodes[curNode] = true;
            child++;
        }else {
            lowestTime[curNode] = min(lowestTime[curNode], initialTime[adjNode]);
        }
    }
    
    if(child > 1 && parentNode == -2) markNodes[curNode] = true;
}

vector<int> articulationPoints(int V, vector<int>adj[]) {
    int timer = 0;
    
    vector<int> initialTime(V,-1);
    vector<int> lowestTime(V,0);
    
    vector<bool> markNodes(V,false);
    
    dfsTraversal(0, -2, timer, initialTime, lowestTime, markNodes, adj);
    
    vector<int> result;
    
    for(int i=0;i<V;i++) if(markNodes[i]) result.push_back(i);
    
    if(result.size() == 0) return {-1};
    return result;
}