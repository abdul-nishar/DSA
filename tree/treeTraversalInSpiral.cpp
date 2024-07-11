#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

vector<int> treeTraversalInSpiral(TreeNode* root) {
    vector<int> result;

    return result;
}

int main(){
    TreeNode * root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->right->left->left = new TreeNode(10);

    vector<int> result = treeTraversalInSpiral(root);

    for(auto value : result) cout << value << " ";

    return 0;
}