#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int helperFunc(TreeNode* root, int& curMax) {
    if(root == nullptr) return 0;

    int leftSum = helperFunc(root->left, curMax);
    int rightSum = helperFunc(root->right, curMax);

    // This stores the maximum value out of the root->data, root->data + leftSubTree, root->data + rightSubTree
    int singlePathSum = max(root->data, max(leftSum, rightSum) + root->data);

    // This stores the maximum value out of the singlePathSum and the sum of leftSubTree + root->data + rightSubTree
    int overallMax = max(singlePathSum, leftSum + rightSum + root->data);

    curMax = max(curMax, overallMax);

    return singlePathSum;
}

int maxPathSum(TreeNode* root){
    int curMax = INT_MIN;

    helperFunc(root, curMax);

    return curMax;
}

int main(){
    TreeNode * root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(-25);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(20);

    cout << maxPathSum(root);

    return 0;
}