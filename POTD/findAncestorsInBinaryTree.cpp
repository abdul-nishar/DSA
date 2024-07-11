#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void helperFunc(TreeNode* root, TreeNode* prevRoot, int target, vector<int>& result){
        
    if(root == nullptr) return;
    if(root->data == target){
        if (prevRoot != nullptr) result.push_back(prevRoot->data);
        return;
    }
    
    helperFunc(root->left, root, target, result);
    
    if(!result.empty()){
        if(prevRoot != nullptr) result.push_back(prevRoot->data);
        return;
    }
    
    helperFunc(root->right, root, target, result);
    
    if (!result.empty() && prevRoot != nullptr) {
        result.push_back(prevRoot->data);
    }
}

vector<int> Ancestors(TreeNode *root, int target) {
    vector<int> result;
    
    helperFunc(root, nullptr, target, result);

    return result;
}

int main(){
    TreeNode * root = new TreeNode(19);

    root->left = new TreeNode(10);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(13);

    vector<int> result = Ancestors(root,13);

    for(auto value : result) cout << value << " ";
    return 0;
}