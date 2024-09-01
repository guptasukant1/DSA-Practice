#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

// $ Preorder, Inorder, and Postorder Combined
// $ TC: O(3*n) | SC: O(4*n)
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

vvi preInPostTraversal(Node* root){
    vi pre, in, post;
    if(!root) return {};
    stack<pair<Node*, int>> st;

    st.push({root, 1});

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        // * Preorder
        if(it.second == 1){
            pre.push_back(it.first -> data);
            it.second = 2;
            st.push(it);
            if(it.first -> left) st.push({it.first -> left, 1});
        }
        // * Inorder
        else if(it.second == 2){
            in.push_back(it.first -> data);
            it.second = 3;
            st.push(it);
            if(it.first -> right) st.push({it.first -> right, 1});
        }
        // * Postorder
        else post.push_back(it.first -> data);
    }
    vvi result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> pre, in, post;
    vector<vector<int>> traversals = preInPostTraversal(root);

    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
