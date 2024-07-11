#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void postOrderTraversal(TreeNode *root){
    if(root == nullptr) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    cout << root->data << " ";
}

int main(){
    TreeNode * root = new TreeNode(19);

    root->left = new TreeNode(10);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(13);

    postOrderTraversal(root);

    return 0;
}