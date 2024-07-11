#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void levelOrderTraversal(TreeNode *root) {
    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);

    while(!nodesQueue.empty()){
        cout << nodesQueue.front()->data << " ";
        if(nodesQueue.front()->left != nullptr) nodesQueue.push(nodesQueue.front()->left);
        if(nodesQueue.front()->right != nullptr) nodesQueue.push(nodesQueue.front()->right);

        nodesQueue.pop();
    }
}

TreeNode *createTree(vector<int> parent){
   TreeNode* root = nullptr;
   unordered_map<int, TreeNode*> rootNodes;
   
   for(int i=0;i<parent.size();i++){
       
       if(!rootNodes.count(i)) rootNodes[i] = new TreeNode(i);
       
       if(parent[i] == -1) root = rootNodes[i];
       else{
           if(!rootNodes.count(parent[i])) rootNodes[parent[i]] = new TreeNode(parent[i]);
           
           TreeNode* parentNode = rootNodes[parent[i]];
           if(parentNode->left == nullptr){
                parentNode->left = rootNodes[i];
            }else parentNode->right = rootNodes[i];
       }
   }
   
   return root;
}

int main(){
    vector<int> parentArr = {-1,0,0,1,1,3,5};

    TreeNode* root = createTree(parentArr);

    levelOrderTraversal(root);

    return 0;
}