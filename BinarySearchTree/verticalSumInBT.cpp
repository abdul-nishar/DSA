#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void helperFunc(TreeNode *root, int dist, map<int, int>& m){
    if(!root) return;

    if(m.count(dist)) m[dist] += root->data;
    else m[dist] = root->data;

    helperFunc(root->left, dist - 1, m);
    helperFunc(root->right, dist + 1, m);
}

vector<int> verticalSumInBT(TreeNode* root) {
    vector<int> result;
    map<int, int> m;

    helperFunc(root, 0, m);

    for(auto pair : m) result.push_back(pair.second);

    return result;
}

int main(){
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(15);
    root->right = new TreeNode(25);

    root->left->left = new TreeNode(35);
    root->left->right = new TreeNode(20);

    root->left->left->left = new TreeNode(40);
    root->left->right->right = new TreeNode(75);
    
    root->left->right->right->right = new TreeNode(80);



    vector<int> result = verticalSumInBT(root);

    for(auto value : result) cout << value << " ";

return 0;
}