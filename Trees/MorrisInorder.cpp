#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Morris Inorder Traversal

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
// ! REDO THE CONCEPT

class Solution{
public:
    vi getInorder(Node* root){
        vi inorder;
        Node* cur = root;
        while(cur != nullptr){
            if(cur -> left == nullptr){
                inorder.push_back(cur -> data);
                cur = cur -> right;
            }
            else{
                Node* prev = cur -> left;
                while(prev -> right && prev -> right != cur) prev = prev -> right;
                if(prev -> right == nullptr){
                    prev -> right = cur;
                    cur = cur -> left;
                }
                else{
                    prev -> right = nullptr;
                    inorder.push_back(cur -> data);
                    cur = cur -> right;
                }
            }
        }
        return inorder;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    Solution sol;
    
    vector<int> inorder = sol.getInorder(root);

    cout << "Binary Tree Morris Inorder Traversal: ";
    for(int i = 0; i< inorder.size(); i++){
        cout << inorder[i] << " ";
    }
    cout << endl;
}