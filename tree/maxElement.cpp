#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Method-1
int maxElement1(TreeNode *root) {
    int maxValue = INT_MIN;
    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);

    while(!nodesQueue.empty()){
        if(nodesQueue.front()->data > maxValue) maxValue = nodesQueue.front()->data;
        if(nodesQueue.front()->left != nullptr) nodesQueue.push(nodesQueue.front()->left);
        if(nodesQueue.front()->right != nullptr) nodesQueue.push(nodesQueue.front()->right);

        nodesQueue.pop();
    }

    return maxValue;
}

// Method-2
int maxElement2(TreeNode *root) {
    if(root == nullptr) return INT_MIN;
    else return max(root->data, max(maxElement2(root->left), maxElement2(root->right)));
}

int main(){
    TreeNode * root = new TreeNode(19);

    root->left = new TreeNode(10);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(13);

    cout << maxElement2(root);

    return 0;
}