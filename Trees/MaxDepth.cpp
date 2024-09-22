#include<bits/stdc++.h>
using namespace std;

// $ Max Depth of BT
// $ TC: O(n) | SC: O(n)
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
    int maxDepth(Node* root){
        if(!root) return 0;
        int leftS = maxDepth(root -> left);
        int rightS = maxDepth(root -> right);
        return 1 + max(leftS, rightS);
    }

    int maxDepth1(Node* root){
        if(!root) return 0;
        queue<Node*> q;
        int level = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node* frontN = q.front();
                q.pop();
                if(frontN -> left) q.push(frontN -> left);
                if(frontN -> right) q.push(frontN -> right);
            }
            level++;
        }
        return level;
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
    int depth = solution.maxDepth(root);
    cout << "Maximum depth of the binary tree: " << depth << endl;
    Solution s1;
    int d1 = s1.maxDepth1(root);
    cout << "Maximum depth of the binary tree: " << d1 << endl;

    return 0;
}