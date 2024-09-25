#include<bits/stdc++.h>
using namespace std;

// $ Balanced Height BT [All the nodes in the BT are balanced i.e. the abs(lh - rh) <= 1]

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
    // $ Brute Force Approach
    // $ TC: O(n^2 (each node's height is found)) | SC: O(1)
    bool isBalanced(Node* root){
        if(!root) return 0;
        int lh = getHeight(root -> left);
        int rh = getHeight(root -> right);
        if(abs(lh - rh) <= 1 && isBalanced(root -> left) && isBalanced(root -> right)) return true;
        return false;
    }
    int getHeight(Node* root){
        if(!root) return 0;
        int lh = getHeight(root -> left);
        int rh = getHeight(root -> right);
        return 1 + max(lh, rh);
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    Solution solution;

    if (solution.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
}
