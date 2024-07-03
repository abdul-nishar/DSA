#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x): data(x),next(nullptr) {}
};

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};


void arrayToBinaryTreeHelper(vector<int> vec, TreeNode*& treeNode, int index) {
    if (index >= vec.size()) {
        return;
    }

    treeNode->data = vec[index];

    if (2 * index + 1 < vec.size()) {
        arrayToBinaryTreeHelper( vec,treeNode->left, 2 * index + 1);
    }

    if (2 * index + 2 < vec.size()) {
        arrayToBinaryTreeHelper( vec, treeNode->right, 2 * index + 2);
    }

}
// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) {
    vector<int> numbers;
    while(head!=nullptr) numbers.push_back(head->data);

    arrayToBinaryTreeHelper(numbers, root, 0);
}