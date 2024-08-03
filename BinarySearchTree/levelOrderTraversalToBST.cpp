#include <iostream>
#include <vector>
#include <queue>

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

TreeNode* levelOrderTraversalToBST(vector<int> nums){
    queue<pair<TreeNode*,pair<int,int>>> q;

    int n = nums.size();
    
    TreeNode* root = new TreeNode(nums[0]);
    
    q.push({root, {INT_MIN,INT_MAX}});

    int i = 1;
    while (!q.empty() && i < n) {
        
        TreeNode* node = q.front().first;
        int minBound = q.front().second.first;
        int maxBound = q.front().second.second;
        
        q.pop();

        if (i < n && nums[i] < node->data && nums[i] > minBound) {
            node->left = new TreeNode(nums[i]);
            q.push({node->left, {minBound, node->data}});
            i++;
        }

        if (i < n && nums[i] > node->data && nums[i] < maxBound) {
            node->right = new TreeNode(nums[i]);
            q.push({node->right, {node->data, maxBound}});
            i++;
        }
    }

    return root;
}

int main(){
    vector<int> nums = {7,4,12,3,6,8,1,5,10};

    TreeNode* root = levelOrderTraversalToBST(nums);

    preOrderTraversal(root);

    return 0;
}