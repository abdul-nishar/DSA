#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    int leftCount;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr), leftCount(0) {}
};

TreeNode* insertNode(TreeNode* root, int value){
    TreeNode *newNode = new TreeNode(value);

    if(!root) return newNode;
    
    TreeNode *mover = root;

    while(mover){
        if(mover->data > value){
            mover->leftCount++;
            if(!mover->left){
                mover->left = newNode;
                break;
            }
            mover = mover->left;
        }else {
            if(!mover->right){
                mover->right = newNode;
                break;
            }
            mover = mover->right;
        }
    }

    return root;
}

TreeNode* findMaxNode(TreeNode* root){
    while(root->right) root = root->right;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int value){
    if(!root) return nullptr;

    if(root->data > value){
        root->left = deleteNode(root->left, value);
        if(root->left) root->leftCount--;
    }else if(root->data < value) root->right = deleteNode(root->right, value);
    else {
        if(!root->left){
            TreeNode *rightChild = root->right;
            delete root;
            return rightChild;
        }else if(!root->right){
            TreeNode *leftChild = root->left;
            delete root;
            return leftChild;
        }else {
            TreeNode *maxNode = findMaxNode(root->left);
            root->data = maxNode->data;
            root->left = deleteNode(root->left, maxNode->data);
            root->leftCount--;
        }
    }

    return root;
}

int kThSmallest(TreeNode* root, int k){
    while(root){
        if(root->leftCount + 1 == k) return root->data;
        else if(root->leftCount + 1 < k){
            k -= (root->leftCount + 1);
            root = root->right;
        }else root = root->left;
    }

    return -1;
}

int main(){

    return 0;
}