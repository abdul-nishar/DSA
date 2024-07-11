#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int heightAndDiameter(TreeNode* root, int curDiameter){
    if(root == nullptr) return 0;
    int leftSubTreeHeight = heightAndDiameter(root->left, curDiameter);
    int rightSubTreeHeight = heightAndDiameter(root->right, curDiameter);

    curDiameter = max(curDiameter, leftSubTreeHeight + rightSubTreeHeight + 1);

    return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
}

int diameterOfBT(TreeNode* root){
    int curDiamter = 0;
    heightAndDiameter(root, curDiamter);
    
    return curDiamter;
}

int main(){
    TreeNode * root = nullptr;

    cout << diameterOfBT(root);

    return 0;
}