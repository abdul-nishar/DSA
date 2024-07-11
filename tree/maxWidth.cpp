#include <iostream>
#include <queue>


using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int maxWidth(TreeNode* root) {
    queue<TreeNode*> nodesQueue;
    int maxWidth = 0;
    nodesQueue.push(root);

    while(!nodesQueue.empty()){
        int count = nodesQueue.size();
        maxWidth = max(maxWidth, count);
        for(int i = 0; i< count; i++){
            if(nodesQueue.front()->left != nullptr) nodesQueue.push(nodesQueue.front()->left);
            if(nodesQueue.front()->right != nullptr) nodesQueue.push(nodesQueue.front()->right);
            nodesQueue.pop();
        }
    }

    return maxWidth;
}

int main(){
    TreeNode * root = new TreeNode(10);

    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->right->left = new TreeNode(50);
    root->right->right = new TreeNode(60);
    root->left->left->left = new TreeNode(80);

    cout << maxWidth(root);

    return 0;
}