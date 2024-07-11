#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Recursive Solution
void preOrderTraversal(TreeNode *root){
    if(root == nullptr) return;
    cout << root->data << " ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Iterative Solution
void preOrderTraversal2(TreeNode *root){
    stack<TreeNode*> nodeStack;
    TreeNode *mover = root;

    while(mover!= nullptr || !nodeStack.empty()){

        if(mover == nullptr){
            mover = nodeStack.top();
            nodeStack.pop();
        }

        cout << mover->data << " ";
        if(mover->right!=nullptr) nodeStack.push(mover->right);
        mover = mover->left;
    }
}

int main(){
    TreeNode* root = new TreeNode(1);
    
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);

    preOrderTraversal2(root);

    return 0;
}