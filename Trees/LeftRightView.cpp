#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>


// $ Right and Left View of a Binary Tree

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val),
        left(nullptr), right(nullptr) {}
};

// $ Brute Force Approach [Perform Level Order Traversal on the tree and then obtain the first element from each level in the 2D Array for RView and the last element for LView]
// $ TC: O(n) | SC: O(n)
class Solution{
    public:
    vi RView(Node* root){
        vi res;
        vvi levelTraversal = levelOrder(root);
        for(auto level: levelTraversal) res.push_back(level.back());
        return res;
    }

    vi LView(Node* root){
        vi res;
        vvi levelTraversal = levelOrder(root);
        for(auto level: levelTraversal) res.push_back(level.front());
        return res;
    }

    private:
    vvi levelOrder(Node* root){
        vvi ans;
        if(!root) return ans;
        queue<Node* > q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vi level;

            for(int i = 0; i < size; i++){
                Node* top = q.front();
                level.push_back(top -> data);
                q.pop();
                if(top->left) q.push(top -> left);
                if(top->right) q.push(top -> right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

// $ Optimal Approach
// $ TC: O(log2n -> n) | SC: O(log2n -> n) [both proportional to height of BT, if skewed them only O(n)] [O(H) recursive stack space]
class Solution1{
    public:
    vi RViewOA(Node* root){
        vi res;
        recursionRight(root, 0, res);
        return res;
    }

    vi LViewOA(Node* root){
        vi res;
        recursionLeft(root, 0, res);
        return res;
    }
    private:

    void recursionRight(Node* root, int level, vi res){
        if(!root) return;
        if(res.size() == level) res.push_back(root -> data);
        recursionRight(root -> right, level + 1, res);
        recursionLeft(root -> left, level + 1, res);
    }

    void recursionLeft(Node* root, int level, vi res){
        if(!root) return;
        if(res.size() == level) res.push_back(root -> data);
        recursionLeft(root -> left, level + 1, res);
        recursionRight(root -> right, level + 1, res);
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

    vector<int> rightView = solution.RView(root);

    cout << "Right View Traversal: ";
    for(auto node: rightView){
        cout << node << " ";
    }
    cout << endl;

    vector<int> leftView = solution.LView(root);

    cout << "Left View Traversal: ";
    for(auto node: leftView){
        cout << node << " ";
    }
    cout << endl;

    cout << "Optimal: " << endl;
    Solution1 s1;

    vector<int> rightView1 = s1.RViewOA(root);

    cout << "Right View Traversal: ";
    for(auto node: rightView){
        cout << node << " ";
    }
    cout << endl;

    vector<int> leftView1 = s1.LViewOA(root);

    cout << "Left View Traversal: ";
    for(auto node: leftView){
        cout << node << " ";
    }
    cout << endl;

}