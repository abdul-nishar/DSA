#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int heightOfBinaryTree(TreeNode *root) {
    if(root == nullptr) return 0;
    else return max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right)) + 1;
}

int main(){
    TreeNode * root = new TreeNode(19);

    root->left = new TreeNode(10);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(13);

    cout << heightOfBinaryTree(root);

    return 0;
}