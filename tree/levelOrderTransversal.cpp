#include <iostream>
#include <queue>


using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int heightOfBinaryTree(TreeNode *root) {
    if(root == nullptr) return 0;
    else return max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right)) + 1;
}

void printNodesatK (TreeNode *root, int k){
    if(k==0) {cout << root->data << " ";return;}

    if(root->left!=nullptr) printNodesatK(root->left, k-1);
    if(root->right!=nullptr) printNodesatK(root->right, k-1);
}

void levelOrderTraversal1(TreeNode *root) {
    int height = heightOfBinaryTree(root);
    int count = 0;
    while(count < height){
        printNodesatK(root, count++);
    }
}

// Efficient Method
void levelOrderTraversal2(TreeNode *root) {
    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);

    while(!nodesQueue.empty()){
        cout << nodesQueue.front()->data << " ";
        if(nodesQueue.front()->left != nullptr) nodesQueue.push(nodesQueue.front()->left);
        if(nodesQueue.front()->right != nullptr) nodesQueue.push(nodesQueue.front()->right);

        nodesQueue.pop();
    }
}

int main(){
    TreeNode * root = new TreeNode(10);

    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->right = new TreeNode(60);
    root->right->right->left = new TreeNode(70);


    levelOrderTraversal2(root);

    return 0;
}