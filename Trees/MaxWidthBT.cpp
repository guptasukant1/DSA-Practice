#include<bits/stdc++.h>
using namespace std;

// $ Maximum width of a Binary Tree
// $ TC: O(n) | SC: O(n)
struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
        int widthOfBinaryTree(Node* root){
            int ans = INT_MIN;
            if(!root) return ans;

            queue<pair<Node*, long long>> q;
            q.push({root, 0});

            while(!q.empty()){
                long long size = q.size();
                long long minIndex = q.front().second; // * Position of first node of level
                int first, last;

                for(int i = 0; i < size; i++){ // * Traverse the level
                    long long cur_n = q.front().second - minIndex; // * Position of each node in the level
                    Node* node = q.front().first; // * To access the left and right child nodes
                    q.pop();

                    if(i == 0) first = cur_n;
                    if(i == size - 1) last = cur_n;
                    if(node -> left) q.push({node -> left, cur_n * 2});
                    if(node -> right) q.push({node -> right, cur_n * 2 + 1});
                }
                ans = max(ans, last - first + 1);
            }
            return ans;
        }
};

int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Solution sol;

    int maxWidth = sol.widthOfBinaryTree(root);

    cout << "Maximum width of the binary tree is: "
                        << maxWidth << endl;

    return 0;
}