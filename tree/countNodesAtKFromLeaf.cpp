#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int treeHeight(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

void tranverseAndCountTree(TreeNode *root, int& count, vector<bool>& visited, int pathLen, int k){
    if(root == nullptr) return;

    if(pathLen >= visited.size()) visited.push_back(false);
    else visited[pathLen] = false;

    pathLen++;

    // Check if this is a leaf node
    if(root->left == nullptr && root->right == nullptr){
        if(pathLen - k - 1 >= 0 && !visited[pathLen - k - 1]){
            count++;
            visited[pathLen - k - 1] = true;
        }
        return;
    } 

    tranverseAndCountTree(root->left, count, visited, pathLen, k);
    tranverseAndCountTree(root->right, count, visited, pathLen, k);
}

int countNodesAtKFromLeaf(TreeNode *root, int k) {
    int count = 0;
    int height = treeHeight(root);

    // Vector to check if the special node has already been visited
    vector<bool> visited(height,false);

    tranverseAndCountTree(root, count, visited, 0, k);

    return count;
}

int main(){
    TreeNode * root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);

    cout << countNodesAtKFromLeaf(root, 2) << endl;

    return 0;
}