#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

struct Pair{
    TreeNode* node;
    int dist;
    
    Pair(TreeNode* n,int d) : node(n), dist(d) {}
};

vector<int> verticalOrder(TreeNode *root){
    vector<int> result;

    if(!root) return result;

    map<int,vector<int>> m;
    queue<Pair> q;
    
    q.push(Pair(root, 0));
    
    while(!q.empty()){
        Pair cur = q.front();
        q.pop();

        m[cur.dist].push_back(cur.node->data);
        
        if(cur.node->left) q.push(Pair(cur.node->left, cur.dist - 1));
        if(cur.node->right) q.push(Pair(cur.node->right, cur.dist + 1));
    }
    
    for(auto pair : m){
        for(auto val : pair.second) result.push_back(val);
    }
    
    return result;
}

int main(){
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(20);
    root->right = new TreeNode(30);

    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);

    vector<int> result = verticalOrder(root);

    for(auto val : result) cout << val << " ";

return 0;
}