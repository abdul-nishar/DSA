#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool compareNodes(TreeNode* tree1, TreeNode* tree2){
    if(tree1==nullptr && tree2==nullptr) return true;
    if(tree1==nullptr || tree2==nullptr) return false;
    if(tree1->data != tree2->data) return false;
    
    return compareNodes(tree1->left, tree2->left) && compareNodes(tree1->right, tree2->right);
}

bool checkIfSubtree(TreeNode *T, TreeNode *S) {
    if (S == nullptr) return true;
    if (T == nullptr) return false; 

    if (compareNodes(T, S)) return true;

    return checkIfSubtree(T->left, S) || checkIfSubtree(T->right, S);
}

int main(){
    TreeNode * root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);

    TreeNode * subroot = new TreeNode(3);


    cout << boolalpha << checkIfSubtree(root, subroot);

    return 0;
}