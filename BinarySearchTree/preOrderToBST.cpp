#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(TreeNode* root){
    if(!root) return;

    preOrderTraversal(root->left);

    cout << root->data << " ";

    preOrderTraversal(root->right);
}

TreeNode* helperFunc(vector<int> vec, int start, int end){
    if(start > end) return nullptr;

    TreeNode* root = new TreeNode(vec[start]);

    if(start == end) return root;

    int pivot = start + 1;

    while(pivot < end && vec[pivot] < vec[start]) pivot++;

    root->left = helperFunc(vec, start + 1, pivot - 1);
    root->right = helperFunc(vec, pivot, end);

    return root;
}


TreeNode* preOrderToBST(vector<int> vec) {
    if(vec.empty()) return nullptr;

    return helperFunc(vec, 0, vec.size() - 1);
}

int main(){
    vector<int> nums = {40,30,35,80,100};

    TreeNode* root = preOrderToBST(nums);

    preOrderTraversal(root);

    return 0;
}