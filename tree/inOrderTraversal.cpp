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
void inOrderTraversal(TreeNode *root){
    if(root == nullptr) return;

    inOrderTraversal(root->left);

    cout << root->data << " ";

    inOrderTraversal(root->right);

}

// Iterative Solution
void inOrderTraversal2(TreeNode *root){
    stack<TreeNode*> nodeStack;

    TreeNode* mover = root;

    while(mover != nullptr || !nodeStack.empty()){

        while(mover!=nullptr) {
            nodeStack.push(mover);
            mover = mover->left;
        }

        mover = nodeStack.top();
        nodeStack.pop();

        cout << mover->data << " ";

        mover = mover->right;
    }
}

int main(){
    TreeNode * root = new TreeNode(10);

    root->left = new TreeNode(20);
    root->right = new TreeNode(70);
    root->right->right = new TreeNode(90);
    root->right->right->left = new TreeNode(100);

    root->left->left = new TreeNode(30);
    root->left->right = new TreeNode(40);
    root->left->right->left = new TreeNode(50);
    root->left->right->right = new TreeNode(60);

    inOrderTraversal2(root);

    return 0;
}