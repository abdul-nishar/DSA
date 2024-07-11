#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void inOrderTransveral(TreeNode *root){
    if(root == nullptr) return;

    inOrderTransveral(root->left);

    cout << root->data << " ";

    inOrderTransveral(root->right);

}

void mirrorBinaryTree(TreeNode* root) {
    if(root == nullptr) return;

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main(){
    TreeNode * root = new TreeNode(19);

    root->left = new TreeNode(10);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(13);

    inOrderTransveral(root);

    cout << endl;

    mirrorBinaryTree(root);

    inOrderTransveral(root);

    return 0;
}