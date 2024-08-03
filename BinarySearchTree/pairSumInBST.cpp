#include <iostream>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool helperFunc(TreeNode* root, int sum, unordered_set<int>& hashSet){
    if(!root) return false;

    if(helperFunc(root->left, sum, hashSet) == true) return true;

    if(hashSet.count(sum - root->data)) return true;
    else hashSet.insert(root->data);

    return helperFunc(root->right, sum, hashSet);
}

bool pairSumInBST(TreeNode* root, int sum) {
    unordered_set<int> hashSet;

    return helperFunc(root, sum, hashSet);
}

int main(){

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(8);
    root->right = new TreeNode(20);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(30);

    root->right->right->left = new TreeNode(25);

    cout << boolalpha << pairSumInBST(root, 33);

    return 0;
}