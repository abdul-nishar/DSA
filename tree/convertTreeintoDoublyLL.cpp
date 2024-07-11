#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void convertTreeintoDoublyLLHelper(TreeNode* root, TreeNode*& head, TreeNode*& prev) {
    if(root == nullptr) return;

    convertTreeintoDoublyLLHelper(root->left, head, prev);

    if(prev == nullptr) head = root;
    else {
        root->left = prev;
        prev->right = root;
    }

    prev = root;

    convertTreeintoDoublyLLHelper(root->right, head, prev);
}

TreeNode* convertTreeintoDoublyLL(TreeNode *root){
    TreeNode *head = nullptr, *prev = nullptr;

    convertTreeintoDoublyLLHelper(root, head, prev);

    return head;
}

int main(){
    TreeNode * root = new TreeNode(19);

    root->left = new TreeNode(10);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(13);

    TreeNode* head = convertTreeintoDoublyLL(root);

    return 0;
}