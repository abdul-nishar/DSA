#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

vector <int> zigZagTraversal(TreeNode* root){
    vector<int> result;
    deque<TreeNode*> nodesDeque;
    int value = 0;
    
    nodesDeque.push_back(root);
    
    while(!nodesDeque.empty()){
        
        int count = nodesDeque.size();
        
        for(int i=0;i<count;i++){
            if(value % 2 == 0) {
                result.push_back(nodesDeque.front()->data);
                nodesDeque.push_back(nodesDeque.front());
                nodesDeque.pop_front();
            }
            else {
                result.push_back(nodesDeque.back()->data);
                nodesDeque.push_front(nodesDeque.back());
                nodesDeque.pop_back();
            }
        }
        
        for(int i=0;i<count;i++){
            if(nodesDeque.front()->left != nullptr) nodesDeque.push_back(nodesDeque.front()->left);
            if(nodesDeque.front()->right != nullptr) nodesDeque.push_back(nodesDeque.front()->right);  

            nodesDeque.pop_front();
        }
        value++;
    }
    
    return result;
}

int main(){
    TreeNode * root = new TreeNode(19);

    root->left = new TreeNode(10);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(13);

    vector<int> result = zigZagTraversal(root);

    for(auto value : result) cout << value << " ";

    return 0;
}