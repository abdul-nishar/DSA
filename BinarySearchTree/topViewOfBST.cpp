#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

struct Pair{
    TreeNode *node;
    int dist;

    Pair(TreeNode *n, int d) : node(n), dist(d) {}
};

vector<int> topViewOfBST(TreeNode *root) {
    vector<int> result;

    if(!root) return result;

    map<int,int> m;
    queue<Pair> q;

    q.push(Pair(root, 0));

    while(!q.empty()){
        Pair cur = q.front();
        q.pop();

        if(!m.count(cur.dist)) m[cur.dist] = cur.node->data;

        if(cur.node->left) q.push(Pair(cur.node->left, cur.dist - 1));
        if(cur.node->right) q.push(Pair(cur.node->right, cur.dist + 1));
    }

    for(auto pair : m) result.push_back(pair.second);

    return result;
}

int main(){
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(20);
    root->right = new TreeNode(50);

    root->left->left = new TreeNode(30);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);

    // root->left->left->left = new TreeNode(5);
    // root->left->left->right = new TreeNode(15);
    // root->left->right->left = new TreeNode(23);
    // root->left->right->right = new TreeNode(28);
    // root->right->left->left = new TreeNode(33);
    // root->right->left->right = new TreeNode(38);
    // root->right->right->left = new TreeNode(45);
    // root->right->right->right = new TreeNode(55);

    vector<int> result = topViewOfBST(root);

    for(auto val : result) cout << val << " ";

    return 0;
}