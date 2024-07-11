#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(TreeNode *root){
    if(root == nullptr) return;
    cout << root->data << " ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void deepestValue(TreeNode* root, int& deepestVal, TreeNode*& parent, TreeNode*& deepestNode) {
    if (root == nullptr) return;

    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        TreeNode* current = nodeQueue.front();
        nodeQueue.pop();

        if (current->left) {
            parent = current;
            deepestNode = current->left;
            nodeQueue.push(current->left);
        }
        if (current->right) {
            parent = current;
            deepestNode = current->right;
            nodeQueue.push(current->right);
        }

        if (!current->left && !current->right) {
            deepestVal = current->data;
        }
    }
}

void deletionBT(TreeNode* root, int target) {
    if (root == nullptr) return;

    // If tree has only one node and it's the target
    if (root->data == target && !root->left && !root->right) {
        delete root;
        root = nullptr;
        return;
    }

    int deepestVal;
    TreeNode* parent = nullptr;
    TreeNode* deepestNode = root;

    deepestValue(root, deepestVal, parent, deepestNode);

    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        TreeNode* current = nodeQueue.front();
        nodeQueue.pop();

        if (current->data == target) {
            current->data = deepestVal;
            // Remove the deepest node
            if (parent->left == deepestNode) parent->left = nullptr;
            else if (parent->right == deepestNode) parent->right = nullptr;
            delete deepestNode;
            return;
        }

        if (current->left) nodeQueue.push(current->left);
        if (current->right) nodeQueue.push(current->right);
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

    preOrderTraversal(root);

    cout << endl;

    deletionBT(root, 12);

    preOrderTraversal(root);

    return 0;
}