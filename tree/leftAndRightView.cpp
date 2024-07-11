#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Iterative Method
void leftViewIterative(TreeNode * root) {
    queue<TreeNode*> nodesQueue;

    nodesQueue.push(nullptr);
    nodesQueue.push(root);

    while(nodesQueue.size() > 1){
        
        if(nodesQueue.front() == nullptr) {
            nodesQueue.pop();
            cout << nodesQueue.front()->data << " ";
            nodesQueue.push(nullptr);
        }


        if(nodesQueue.front()->left != nullptr) nodesQueue.push(nodesQueue.front()->left);
        if(nodesQueue.front()->right != nullptr) nodesQueue.push(nodesQueue.front()->right);

        nodesQueue.pop();
    }
}


void leftViewHelper(TreeNode * root, int curLevel , int& maxLevel) {
    if(root == nullptr) return;

    if(maxLevel < curLevel){
        cout << root->data << " ";
        maxLevel = curLevel;
    }

    leftViewHelper(root->left, curLevel + 1, maxLevel);
    leftViewHelper(root->right, curLevel + 1, maxLevel);
}

void leftViewRecursive(TreeNode * root){
    int maxLevel = 0;
    leftViewHelper(root, 1, maxLevel);
}

void rightView(TreeNode * root) {
    queue<TreeNode*> nodesQueue;

    nodesQueue.push(nullptr);
    nodesQueue.push(root);

    while(nodesQueue.size() > 1){
        
        if(nodesQueue.front() == nullptr) {
            nodesQueue.pop();
            cout << nodesQueue.front()->data << " ";
            nodesQueue.push(nullptr);
        }

        if(nodesQueue.front()->right != nullptr) nodesQueue.push(nodesQueue.front()->right);
        if(nodesQueue.front()->left != nullptr) nodesQueue.push(nodesQueue.front()->left);

        nodesQueue.pop();
    }
}


int main(){
    TreeNode * root = new TreeNode(19);

    root->left = new TreeNode(10);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(11);
    root->left->right = new TreeNode(13);

    leftViewRecursive(root);

    return 0;
}