#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(TreeNode* root){
    if(root == nullptr) return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

TreeNode* deletionInBST(TreeNode* root, int target) {
    if(root == nullptr) return nullptr;

    TreeNode* current = root;
    TreeNode* parent = nullptr;

    while(current != nullptr && current->data != target){
        parent = current;
        if(current->data > target) current = current->left;
        else current = current->right;
    }

    if(current == nullptr) return root;

    if (current->left && current->right) {
        TreeNode* successorParent = current;
        TreeNode* successor = current->left;
        
        while (successor->right) {
            successorParent = successor;
            successor = successor->right;
        }

        // Swap data
        current->data = successor->data;
        current = successor;  // We will now delete the successor node
        parent = successorParent;
    }

    // Case 2 and Case 3: Node to be deleted has zero or one child
    TreeNode* child = (current->left != nullptr) ? current->left : current->right;

    if (parent == nullptr) {
        // The root node is being deleted
        root = child;
    } else {
        if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    }

    delete current;
    return root;
}

int main(){
    TreeNode* root = new TreeNode(30);

    root->left = new TreeNode(20);
    root->right = new TreeNode(40);

    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(25);
    root->right->left = new TreeNode(35);
    root->right->right = new TreeNode(50);

    root->left->left->left = new TreeNode(5);
    root->left->left->right = new TreeNode(15);
    root->left->right->left = new TreeNode(23);
    root->left->right->right = new TreeNode(28);
    root->right->left->left = new TreeNode(33);
    root->right->left->right = new TreeNode(38);
    root->right->right->left = new TreeNode(45);
    root->right->right->right = new TreeNode(55);

    inOrderTraversal(root);

    TreeNode* newRoot = deletionInBST(root, 30);

    cout << endl;

    inOrderTraversal(newRoot);

    return 0;
}