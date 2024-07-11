#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

struct Node {
    int data;
    Node * next;

    Node(int value) : data(value), next(nullptr) {}
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

void convert(Node *head, TreeNode *&root) {
    if (head == nullptr) return;

    root = new TreeNode(head->data);
    head = head->next;

    queue<TreeNode*> q;
    q.push(root);

    while (head != nullptr) {
        TreeNode* current = q.front();
        q.pop();

        
        TreeNode* leftChild = new TreeNode(head->data);
        current->left = leftChild;
        q.push(leftChild);
        head = head->next;
        if (head == nullptr) break;

        
        TreeNode* rightChild = new TreeNode(head->data);
        current->right = rightChild;
        q.push(rightChild);
        head = head->next;
    }
}

int main(){
    TreeNode* root = nullptr;

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    convert(head, root);

    levelOrderTraversal2(root);

    return 0;
}