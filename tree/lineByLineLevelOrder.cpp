#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void lineByLineLevelOrder1(TreeNode *root) {
    queue<TreeNode*> nodesQueue;

    nodesQueue.push(root);
    nodesQueue.push(nullptr);

    // Loop Condition is important here because if we use !nodesQueue.empty(), then we will always have a nullptr in the queue no matter what
    while(nodesQueue.size() > 1){
        
        if(nodesQueue.front() == nullptr) {
            cout << endl;
            nodesQueue.pop();
            nodesQueue.push(nullptr);
        }

        cout << nodesQueue.front()->data << " ";

        if(nodesQueue.front()->left != nullptr) nodesQueue.push(nodesQueue.front()->left);
        if(nodesQueue.front()->right != nullptr) nodesQueue.push(nodesQueue.front()->right);

        nodesQueue.pop();
    }
}

void lineByLineLevelOrder2(TreeNode *root) {
    queue<TreeNode*> nodesQueue;

    nodesQueue.push(root);

    while(!nodesQueue.empty()) {
        int count = nodesQueue.size();

        for(int i  = 0; i < count; i++) {

            cout << nodesQueue.front()->data << " ";

            if(nodesQueue.front()->left != nullptr) nodesQueue.push(nodesQueue.front()->left);
            if(nodesQueue.front()->right != nullptr) nodesQueue.push(nodesQueue.front()->right);  

            nodesQueue.pop();
        }
        cout << endl;
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

    lineByLineLevelOrder2(root);

    return 0;
}