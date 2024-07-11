#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Method-1 : Two stacks are used to store the ancestors both the values and then compared 

void helperFunc(TreeNode* root, TreeNode* prevRoot, int target, stack<TreeNode*>& result){
        
    if(root == nullptr) return;
    if(root->data == target){
        result.push(root);
        if (prevRoot != nullptr) result.push(prevRoot);
        return;
    }
    
    helperFunc(root->left, root, target, result);
    
    if(!result.empty()){
        if(prevRoot != nullptr) result.push(prevRoot);
        return;
    }
    
    helperFunc(root->right, root, target, result);
    
    if (!result.empty() && prevRoot != nullptr) {
        result.push(prevRoot);
    }
}

stack<TreeNode*> Ancestors(TreeNode *root, int target) {
    stack<TreeNode*> result;
    
    helperFunc(root, nullptr, target, result);

    return result;
}

TreeNode* lowestCommonAncestor(TreeNode* root, int value1, int value2) {
    TreeNode* commonAncestor = nullptr;

    stack<TreeNode*> stack1 = Ancestors(root, value1);
    stack<TreeNode*> stack2 = Ancestors(root, value2);

    while(!stack1.empty() && !stack2.empty() && stack1.top() == stack2.top()) {
        commonAncestor = stack1.top();
        stack1.pop();
        stack2.pop();
    }

    return commonAncestor;
}

// Method-2 : Efficient Method
// This method returns incorrect result when values are not present in the tree

TreeNode* leastCommonAncestor(TreeNode* root, int value1, int value2) {
    if (root == nullptr) return nullptr;
    
    if (root->data == value1 || root->data == value2) return root;
    
    // Look for values in left and right subtrees
    TreeNode* leftLCA = leastCommonAncestor(root->left, value1, value2);
    TreeNode* rightLCA = leastCommonAncestor(root->right, value1, value2);
    
    // If both of the above calls return non-null, then one value is present in one subtree and the other is present in the other subtree. So this node is the LCA.
    if (leftLCA && rightLCA) return root;
    
    // Otherwise check if left subtree or right subtree is LCA
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int main(){
    TreeNode * root = new TreeNode(10);

    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->left->left = new TreeNode(60);
    root->right->right = new TreeNode(50);
    root->right->right->left = new TreeNode(70);
    root->right->right->right = new TreeNode(80);

    TreeNode* result = leastCommonAncestor(root, 60, 70);
    cout << result->data << endl;

    return 0;
}