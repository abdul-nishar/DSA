#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void topViewHelper(TreeNode *root, int curVal, map<int,int>& distanceMap){
    if(root == nullptr) return;

    if(!distanceMap.count(curVal)) {
        distanceMap[curVal] = root->data;
    }

    if(root->left!=nullptr) topViewHelper(root->left, curVal - 1, distanceMap);
    if(root->right!=nullptr) topViewHelper(root->right, curVal + 1, distanceMap);
}

void topView(TreeNode *root) {
    map<int, int> distanceMap;
    int curVal = 0;

    topViewHelper(root, curVal, distanceMap);

    for(auto pair : distanceMap){
        cout << pair.second << " ";
    }
}

void bottomViewHelper(TreeNode *root, int curVal, map<int,int>& distanceMap){
    if(root == nullptr) return;

    if(root->left!=nullptr) bottomViewHelper(root->left, curVal - 1, distanceMap);
    if(root->right!=nullptr) bottomViewHelper(root->right, curVal + 1, distanceMap);


    if(!distanceMap.count(curVal)) {
        distanceMap[curVal] = root->data;
    }

}

void bottomView(TreeNode *root) {
    map<int, int> distanceMap;
    int curVal = 0;

    bottomViewHelper(root, curVal, distanceMap);

    for(auto pair : distanceMap){
        cout << pair.second << " ";
    }
}

int main(){
    TreeNode * root = new TreeNode(10);

    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->right = new TreeNode(50);
    root->right->right = new TreeNode(60);
    root->left->right->left = new TreeNode(70);
    root->left->right->left->left = new TreeNode(40);

    bottomView(root);

    return 0;
}