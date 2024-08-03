#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    int leftCount;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr), leftCount(0) {}
};
    

TreeNode* insert(TreeNode* root, int val, int& count) {
    if (!root) return new TreeNode(val);
    
    if (val <= root->data) {
        root->leftCount++;
        root->left = insert(root->left, val, count);
    } else {
        count += root->leftCount + 1;
        root->right = insert(root->right, val, count);
    }
    
    return root;
}

vector<int> constructLowerArray(vector<int> &arr) {
    TreeNode* root = nullptr;
    vector<int> result(arr.size());
    
    for (int i = arr.size() - 1; i >= 0; --i) {
        int count = 0;
        root = insert(root, arr[i], count);
        result[i] = count;
    }
    
    return result;
}

int main(){
    vector<int> numsArr = {12,1,2,3,0,11,4};
    vector<int>result = constructLowerArray(numsArr);

    for(auto value: result) cout << value << " ";   

    return 0;
}