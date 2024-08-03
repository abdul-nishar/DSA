#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

struct NodeSum {
    TreeNode* current;
    int sum;
    
    NodeSum(TreeNode* node, int value) : current(node), sum(value) {}
};

bool hasPathSum(TreeNode *root, int target) {
    if(!root) return false;
    
    queue<NodeSum> nodeQueue;
    
    nodeQueue.push(NodeSum(root, root->data));
    
    while(!nodeQueue.empty()){
        TreeNode* curNode = nodeQueue.front().current;
        int curSum = nodeQueue.front().sum;
        nodeQueue.pop();
        
        if(!curNode->left && !curNode->right && curSum == target) return true;
        
        if(curNode->left) nodeQueue.push(NodeSum(curNode->left,curSum + curNode->left->data));
        if(curNode->right) nodeQueue.push(NodeSum(curNode->right,curSum + curNode->right->data));
    }
    
    return false;
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    cout << boolalpha << hasPathSum(root, 22);

    return 0;
}