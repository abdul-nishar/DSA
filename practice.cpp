#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(TreeNode * root){
    if(root == nullptr) return;

    cout << root->data << " ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void convertBTtoLL(TreeNode* root, TreeNode*& prev) {
    if(root == nullptr) return;

    convertBTtoLL(root->right, prev);
    convertBTtoLL(root->left, prev);

    root->right = prev;
    root->left = nullptr;

    prev = root;
}

void convertBTtoLL2(TreeNode* root){
    TreeNode* current = root;
    TreeNode* prev = nullptr;
    
    while(current){
        if(current->left){
            prev = current->left;
            while(prev->right) prev = prev->right;

            prev->right = current->right;
            current->right = current->left;
            current->left = nullptr;
        }

        current = current->right;
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

    TreeNode* prev = nullptr;
    convertBTtoLL2(root);

    preOrderTraversal(root);

    return 0;
}