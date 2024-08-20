#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val) : data(val), right(nullptr), left(nullptr) {}
};

// $ Inorder Traversal
// $ TC: O(n) | SC: O(n)
void Inorder(Node* root, vi &arr){
    if(root == nullptr) return;
    Inorder(root -> left, arr);
    arr.push_back(root -> data);
    Inorder(root -> right, arr);
}

vi inOrder(Node* root){
    vi arr;
    Inorder(root, arr);
    return arr;
}

// $ Preorder Traversal
// $ TC: O(n) | SC: O(n)
void Preorder(Node* root, vi &arr){
    if(root == nullptr) return;
    arr.push_back(root -> data);
    Preorder(root -> left, arr);
    Preorder(root -> right, arr);
}

vi preOrder(Node* root){
    vi arr;
    Preorder(root, arr);
    return arr;
}

// $ Postorder Traversal
// $ TC: O(n) | SC: O(n)
void Postorder(Node* root, vi &arr){
    if(root == nullptr) return;
    Postorder(root -> left, arr);
    Postorder(root -> right, arr);
    arr.push_back(root -> data);
}

vi postOrder(Node* root){
    vi arr;
    Postorder(root, arr);
    return arr;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->left = new Node(7);

    vector<int> result = inOrder(root);

    cout << "Inorder Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> result1 = preOrder(root);

    cout << "Preorder Traversal: ";
    for(int val : result1) {
        cout << val << " ";
    }
    cout << endl;
    
    vector<int> result2 = postOrder(root);

    cout << "Postorder Traversal: ";
    for(int val : result2) {
        cout << val << " ";
    }
    cout << endl;

}