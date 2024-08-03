#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(TreeNode* root){
    if(root == nullptr) return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Iterative Solution
TreeNode* insertInBST(TreeNode* root, int value) {
    TreeNode* newNode = new TreeNode(value);

    TreeNode* current = root;

    if(current == nullptr) return newNode;

    while(current!=nullptr){
        if(current->data < value){
            if(current->right) current = current->right;
            else {
                current->right = newNode;
                return root;
            }
        }else {
            if(current->left) current = current->left;
            else {
                current->left = newNode;
                return root;
            }
        }
    }

    return root;
}

// Recursive Solution

TreeNode* insertInBST2(TreeNode* root, int value){
    if(root == nullptr) return new TreeNode(value);

    if(root->data > value) root->left = insertInBST2(root->left, value);
    else root->right = insertInBST2(root->right, value);

    return root;
}

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

    inOrderTraversal(root);

    TreeNode* newRoot = insertInBST2(root, 34);

    cout << endl;

    inOrderTraversal(newRoot);

    return 0;
}