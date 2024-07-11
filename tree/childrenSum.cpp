#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool childrenSum(TreeNode *root) {
    if(root == nullptr) return true;

    if(root->left==nullptr && root->right==nullptr) return true;

    int leftVal = root->left!=nullptr ? root->left->data : 0;
    int rightVal = root->right!=nullptr ? root->right->data : 0;

    if(root->data == leftVal + rightVal) return childrenSum(root->left) && childrenSum(root->right);
    else return false;
}

int main(){
    TreeNode * root = new TreeNode(35);

    root->left = new TreeNode(20);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);

    cout << boolalpha << childrenSum(root);

    return 0;
}