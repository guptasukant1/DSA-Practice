#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Path from Root to given node
// $ TC: O() | SC: O()
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
    bool getPath(Node* root, vi &arr, int x){
        if(!root) return false;
        arr.push_back(root -> data);

        if(root -> data == x) return true; // * Value found
        // $ Perform DFS on next line to explore full depth per node 
        if(getPath(root -> left, arr, x) || getPath(root -> right, arr, x)) return true; // * Recursively search for the L & R subtrees and if x exists here, return true 

        arr.pop_back(); // * x not found in the current subtree so remove the value currently pushed to vi.
        return false; // * Discard the specific subtree / recusive call.
    }

    vi solve(Node* root, int x){
        vi arr;
        if(!root) return arr;
        getPath(root, arr, x);
        return arr; 
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

    int targetLeafValue = 7;

    vector<int> path = sol.solve(root, targetLeafValue);

    cout << "Path from root to leaf with value " << targetLeafValue << ": ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }

}