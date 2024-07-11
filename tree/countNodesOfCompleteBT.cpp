#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int countNodesOfCompleteBT(TreeNode* root) {
    int leftHeight = 0, rightHeight = 0;
    TreeNode* current = root;
    while(current!=nullptr){
        leftHeight++;
        current = current->left;
    }
    current = root;
    while(current!=nullptr){
        rightHeight++;
        current = current->right;
    }

    if(leftHeight==rightHeight) return pow(2, leftHeight) - 1;

    return 1 + countNodesOfCompleteBT(root->left) + countNodesOfCompleteBT(root->right);
}

int main(){
    TreeNode * root = new TreeNode(19);

    root->left = new TreeNode(10);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(13);

    cout << countNodesOfCompleteBT(root);

    return 0;
}