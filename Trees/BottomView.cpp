#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define mii map<int, int>

// $ Bottom View of a Binary Tree
// $ TC: O(n) | SC: O(n/2 + n/2)
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
    vi bottomView(Node* root){
        vi res;
        if(!root) return res;

        mii mpp;
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int VLevel = it.second;

            mpp[VLevel] = node -> data;
            if(node -> left) q.push({node -> left, VLevel - 1});
            if(node -> right) q.push({node -> right, VLevel + 1});
        }

        for(auto it: mpp) res.push_back(it.second);
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    vector<int> bottomView = solution.bottomView(root);

    cout << "Bottom View Traversal: "<< endl;
    for(auto node: bottomView){
        cout << node << " ";
    }
}