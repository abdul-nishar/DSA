#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void serialization(TreeNode* root, vector<int>& result) {
    if(root == nullptr){
        result.push_back(-1);
        return;
    }

    result.push_back(root->data);
    serialization(root->left, result);
    serialization(root->right, result);
}

TreeNode* deserialization(vector<int> treeNodes, int index = 0){
    if(index == treeNodes.size()) return nullptr;

    int value = treeNodes[index];

    if(value == -1) return nullptr;

    TreeNode* root = new TreeNode(value);
    root->left = deserialization(treeNodes, index+1);
    root->right = deserialization(treeNodes, index+1);

    return root;
}

int main(){
    TreeNode * root = new TreeNode(19);

    root->left = new TreeNode(10);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(13);

    vector<int> result;

    serialization(root, result);

    TreeNode* newRoot = deserialization(result);

    cout << newRoot->data << endl;

    return 0;
}