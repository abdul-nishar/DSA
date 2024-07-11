#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void printNodesatK(TreeNode* root, int k) {
    if(k==0) {cout << root->data << endl;return;}

    if(root->left!=nullptr) printNodesatK(root->left, k-1);
    if(root->right!=nullptr) printNodesatK(root->right, k-1);
}

int main(){
    TreeNode * root = new TreeNode(10);

    root->left = new TreeNode(6);
    root->right = new TreeNode(8);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(11);
    root->right->right->right = new TreeNode(12);

    printNodesatK(root, 3);

    return 0;
}