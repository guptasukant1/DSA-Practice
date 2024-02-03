#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node* right;
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout << "Enter the data of the node: ";
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }
    cout << "Input for left child of " << data << " : ";
    root->left = buildTree(root->left);
    cout << "Input for right child of " << data << " : ";
    root->right = buildTree(root->right);
    return root;
}


// $ Construct a tree from inorder and preorder
