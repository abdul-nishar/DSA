#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool checkBST(TreeNode *root, int minVal, int maxVal) {
    if(!root)  return true;

    if(root->data <= minVal || root->data >= maxVal) return false;

    return checkBST(root->left, minVal, root->data) && checkBST(root->right, root->data, maxVal);
}

int main(){
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(5);

    cout << boolalpha << checkBST(root, INT_MIN, INT_MAX);

    return 0;
}