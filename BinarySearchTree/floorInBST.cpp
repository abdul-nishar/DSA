#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* floorInBST(TreeNode *root, int value) {

    if(root == nullptr) return nullptr;

    TreeNode* result = nullptr;

    while(root != nullptr){
        if(root->data == value) return root;

        if(root->data > value) root = root->left;
        else {
            result = root;
            root = root->right;
        }
    }

    return result;
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

    TreeNode* floor = floorInBST(root, 51);

    if(floor) cout << floor->data << endl;
    else cout << "Floor does not exist" << endl;

return 0;
}