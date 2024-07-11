#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

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

TreeNode* helperFunc(int in[], int post[], int indexStart, int indexEnd, int& postIndex){
    if(indexStart > indexEnd) return nullptr;
        
    TreeNode* root = new TreeNode(post[postIndex--]);

    int curRootIndex;

    for(int i = indexStart; i <= indexEnd ; i++){
        if(in[i] == root->data){
            curRootIndex = i;
            break;
        }
    }

    root->right = helperFunc(in, post, curRootIndex + 1, indexEnd, postIndex);
    root->left = helperFunc(in, post, indexStart, curRootIndex - 1, postIndex);
    
    return root;
}

TreeNode* constructBTfromInandPostOrder(int n, int in[], int post[]) {
    int postIndex = n - 1;
    TreeNode* root = helperFunc(in, post, 0, n-1, postIndex);

    return root;
}

int main(){
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    TreeNode* root = constructBTfromInandPostOrder(8, in, post);

    levelOrderTraversal2(root);

    return 0;
}