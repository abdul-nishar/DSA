#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Method - 1

bool compareMaps(unordered_map<int,int> map1, unordered_map<int,int> map2){
    if(map1.size() != map2.size()) return false;
    
    for(auto pair : map1){
        if(!map2.count(pair.first)) return false;
        if(map2[pair.first] != pair.second) return false;
    }
    
    return true;
}

void storeHelper(TreeNode *root, int curVal, unordered_map<int,int>& distanceMap){
    if(root == nullptr) return;

    distanceMap[abs(curVal)]++;

    if(root->left!=nullptr) storeHelper(root->left, curVal - 1, distanceMap);
    if(root->right!=nullptr) storeHelper(root->right, curVal + 1, distanceMap);
}

bool isTreeFoldable1(TreeNode* root){
    if(root == nullptr) return true;
    
    unordered_map<int,int> leftSubTree;
    unordered_map<int,int> rightSubTree;
    
    storeHelper(root->left, -1, leftSubTree);
    storeHelper(root->right, 1, rightSubTree);
    
    return compareMaps(leftSubTree, rightSubTree);
}

// Method - 2 : Without using hashmap

bool isMirror(TreeNode* tree1, TreeNode* tree2) {
    if (tree1 == nullptr && tree2 == nullptr) return true;
    if (tree1 == nullptr || tree2 == nullptr) return false;

    return isMirror(tree1->left, tree2->right) && isMirror(tree1->right, tree2->left);
}

bool isTreeFoldable2(TreeNode* root) {
    if (root == nullptr) return true;
    return isMirror(root->left, root->right);
}

int main(){
    TreeNode * root = new TreeNode(19);

    root->left = new TreeNode(10);

    cout << boolalpha << isTreeFoldable2(root);

    return 0;
}