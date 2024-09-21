#include <iostream>
#include <vector>

using namespace std;

void dfsTraversal(int curNode, int parentNode, int& timer, vector<vector<int>>& adjList, vector<int>& initialTime, vector<int>& lowestTime, vector<vector<int>>& result){

    initialTime[curNode] = lowestTime[curNode] = timer;
    timer++;

    for(auto adjNode : adjList[curNode]){
        // Skipping the parent node since the lowest time of parent node is always going to be smaller than the lowest time of the current node
        if(adjNode == parentNode) continue;
        
        if(initialTime[adjNode] == -1){
            dfsTraversal(adjNode, curNode, timer, adjList, initialTime, lowestTime, result);

            // Updating the lowest time of the current node so that we can keep track that their another way to reach the current node
            lowestTime[curNode] = min(lowestTime[curNode], lowestTime[adjNode]);

            // Checking for critical connection 
            if(lowestTime[adjNode] > initialTime[curNode]) result.push_back({curNode, adjNode});

        }else lowestTime[curNode] = min(lowestTime[curNode], lowestTime[adjNode]);
    }

}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adjList(n);

    for(auto connection : connections){
        adjList[connection[0]].push_back(connection[1]);
        adjList[connection[1]].push_back(connection[0]);
    }

    vector<vector<int>> result;
    // Initializing the initial times to be -1 so that we can check if the nodes are already visited or not
    vector<int> initialTime(n,-1);
    // Required to find out if there is another way to reach the current node
    vector<int> lowestTime(n,0);

    int timer = 0;

    dfsTraversal(0, -1, timer, adjList, initialTime, lowestTime, result);

    return result;
}