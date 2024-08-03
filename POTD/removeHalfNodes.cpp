#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode *removeHalfNodes(TreeNode *root) {
    if (!root) return nullptr;

    root->left = removeHalfNodes(root->left);
    root->right = removeHalfNodes(root->right);
    
    if (root->left && !root->right) {
        TreeNode* newRoot = root->left;
        delete root;
        return newRoot;
    }
    
    if (!root->left && root->right) {
        TreeNode* newRoot = root->right;
        delete root;
        return newRoot;
    }
    
    return root;
}

int main(){
    TreeNode* root = new TreeNode(30);

    root->left = new TreeNode(20);
    root->right = new TreeNode(40);

    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(25);
    root->right->left = new TreeNode(35);
    root->right->right = new TreeNode(50);

    root->left->left->left = new TreeNode(5);
    root->left->left->right = new TreeNode(15);
    root->left->right->left = new TreeNode(23);
    root->left->right->right = new TreeNode(28);
    root->right->left->left = new TreeNode(33);
    root->right->left->right = new TreeNode(38);
    root->right->right->left = new TreeNode(45);
    root->right->right->right = new TreeNode(55);

    TreeNode* newRoot = removeHalfNodes(root);

    return 0;
}