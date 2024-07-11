#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void insertionInBT(TreeNode* root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }

    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    TreeNode *newNode = new TreeNode(value);

    while (!nodeQueue.empty()) {
        TreeNode *current = nodeQueue.front();
        nodeQueue.pop();

        if (current->left == nullptr) {
            current->left = newNode;
            break;
        } else {
            nodeQueue.push(current->left);
        }

        if (current->right == nullptr) {
            current->right = newNode;
            break;
        } else {
            nodeQueue.push(current->right);
        }
    }
}

int main(){
    TreeNode * root = new TreeNode(13);

    root->left = new TreeNode(12);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(19);
    root->right->left = new TreeNode(16);
    root->right->right = new TreeNode(9);

    insertionInBT(root,12);

    return 0;
}