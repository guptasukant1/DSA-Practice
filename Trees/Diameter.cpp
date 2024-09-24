#include<bits/stdc++.h>
using namespace std;

// $ Max Diameter of BT - Number of edges between a path

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
    // $ Brute Force Approach [Finding the heights of l&r subtrees while finding the diameter]
    // $ TC: O(n) | SC: O(n)
    int diameter = 0;
    int calculateHeight(Node* root){
        if(!root) return 0;
        int lh = calculateHeight(root -> left);
        int rh = calculateHeight(root -> right);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(Node* root) {
        calculateHeight(root);
        return diameter;
    }

    // $ Optimal Approach [Finding the heights of l&r subtrees and finding the diameter together thus reducing the steps needed to calculate the l&r heights]
    // * Not much different from BFA but focusses on bottom-top approach and Postorder traversal.
    // $ TC: O(n) | SC: O(1)
    int diameterOfBinaryTreeOA(Node* root){
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
    private:
    int height(Node* root, int &diameter){
        if(!root) return 0;
        int lh = height(root -> left, diameter);
        int rh = height(root -> right, diameter);
        diameter = max(diameter, lh + rh);
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

    int diameter = solution.diameterOfBinaryTree(root);
    cout << "The diameter of the binary tree is: " << diameter << endl;

    int d1 = solution.diameterOfBinaryTreeOA(root);
    cout << "The diameter of the binary tree is: " << d1 << endl;
}
