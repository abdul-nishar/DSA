#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Iterative Solution
bool searchInBST(TreeNode* root, int value) {
    if(root == nullptr) return false;

    while(root != nullptr){
        if(root->data == value) return true;

        if(root->data > value) root = root->left;
        else root = root->right;
    }

    return false;
}

bool searchInBST2(TreeNode* root, int value) {
    if(root == nullptr) return false;

    if(root->data == value) return true;

    if(root->data > value) return searchInBST2(root->left, value);
    else return searchInBST2(root->right, value);

}

// Recursive Solution

int main(){
    TreeNode* root = new TreeNode(30);

    root->left = new TreeNode(20);
    root->right = new TreeNode(40);

    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(25);
    root->right->left = new TreeNode(35);
    root->right->right = new TreeNode(50);

    root->left->left->left = new TreeNode(5);
    root->left->left->right = new TreeNode(15);
    root->left->right->left = new TreeNode(23);
    root->left->right->right = new TreeNode(28);
    root->right->left->left = new TreeNode(33);
    root->right->left->right = new TreeNode(38);
    root->right->right->left = new TreeNode(45);
    root->right->right->right = new TreeNode(55);

    cout << boolalpha << searchInBST2(root, 56);

    return 0;
}