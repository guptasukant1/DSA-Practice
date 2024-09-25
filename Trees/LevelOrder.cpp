#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

// $ Level Order Traversal of BT
// $ TC: O(n) | SC: O(n)
struct Node {
    int data; 
    Node* left; 
    Node* right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node* left, Node* right) : data(x), left(left), right(right) {}
};

class Solution {
    public:
    vvi levelOrder(Node* root){
        vvi ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vi level;
            for(int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();
                level.push_back(node -> data);

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution solution; 
    vector<vector<int>> result = solution.levelOrder(root); 

    cout << "Level Order Traversal of Tree: "<< endl;

    for (const vector<int>& level : result) {
        printVector(level);
    }
}