#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Method - 1 -> Calculates the height of each subtree multiple times
// Time Complexity - O(N^2)
int heightOfBinaryTree(TreeNode *root) {
    if(root == nullptr) return 0;
    else return max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right)) + 1;
}

bool balancedBinaryTree1(TreeNode* root){
    if(root == nullptr) return true;

    int leftHeight = heightOfBinaryTree(root->left);
    int rightHeight = heightOfBinaryTree(root->right);

    if(abs(leftHeight - rightHeight) > 1) return false;
    else return balancedBinaryTree1(root->left) && balancedBinaryTree1(root->right);
}

// Method - 2 : Efficient method -> Checks if current node is balanced while calculating its height

int checkAndCalculateHeight(TreeNode *root) {
    if(root == nullptr) return 0;

    int leftSubTreeHeight = checkAndCalculateHeight(root->left);
    if(leftSubTreeHeight == -1) return -1;

    int rightSubTreeHeight = checkAndCalculateHeight(root->right);
    if(rightSubTreeHeight == -1) return -1;

    if(abs(leftSubTreeHeight - rightSubTreeHeight) > 1) return -1;

    return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
}

bool balancedBinaryTree2(TreeNode* root){
    return checkAndCalculateHeight(root) != -1;
}

int main(){
    TreeNode * root = new TreeNode(3);

    root->left = new TreeNode(40);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(9);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(6);

    cout << boolalpha << balancedBinaryTree2(root);

    return 0;
}