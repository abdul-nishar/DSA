#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int helperFunc(TreeNode* root, int target, int& distance, int& result){
    if(root == nullptr) return 0;

    if(root->data == target) {
        distance = 0;
        return 1;
    }

    int leftDist = -1, rightDist = -1;
    int leftHeight = helperFunc(root->left, target, leftDist, result);
    int rightHeight = helperFunc(root->right, target, rightDist, result);

    if(leftDist != -1){
        distance = leftDist + 1;
        result = max(result, distance + rightHeight);
    }else if(rightDist != -1){
        distance = rightDist + 1;
        result = max(result, distance + leftHeight);
    }

    return max(leftHeight, rightHeight) + 1;
}

int burnTreeFromLeafNode(TreeNode* root, int target) {
    int result = 0;
    int distance = -1;
    helperFunc(root, target, distance, result);

    return result;
}

int main(){
    TreeNode * root = new TreeNode(10);

    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->right = new TreeNode(60);

    cout << burnTreeFromLeafNode(root, 50);

    return 0;
}