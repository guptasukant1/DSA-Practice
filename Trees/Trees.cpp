#include <bits/stdc++.h>
// #include<iostream>
// #include<stack>
// #include<queue>
using namespace std;

// $ Trees

// * Node Creation
class node{
    public:
        int data;
        node* left;
        node *right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// * Tree Node Entries
node* BuildTree(node* root){
    cout << "Enter data for node: ";
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = BuildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = BuildTree(root->right);
    return root;
}

// * LEVEL ORDER TRAVERSAL

void levelOrderTraversal(node* root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node *temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

// * INORDER TRAVERSAL RECURSIVE
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// * INORDER TRAVERSAL ITERATIVE
void inorder_iterative(node* root){
    stack<node *> s;
    node *temp = root;
    while(temp != NULL || !s.empty()){
        while(temp != NULL){
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        cout << temp->data << " ";
        temp = temp->right;
    }
}

// * PREORDER TRAVERSAL RECURSIVE
void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// * PREORDER TRAVERSAL ITERATIVE
void preorder_iterative(node* root){
	if(root == NULL){
		return;
	}
	stack<node *> s;
	s.push(root);
	while(!s.empty()){
		node *temp = s.top();
		cout << temp->data << " ";
		s.pop();
		if(temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);
	}

	// node *temp = root;
	// while (!s.empty() || temp != NULL)
	// {
	// 	while(temp != NULL){
	// 		cout << temp->data << " ";
	// 		if(temp->right){
	// 			s.push(temp->right);
	// 		}

	// 		temp = temp->left;
	// 	}
	// 	if(!s.empty()){
	// 		temp == s.top();
	// 		s.pop();
	// 	}
	// }
}


// * POSTORDER TRAVERSAL RECURSIVE
void postorder(node* root){
    if(root == NULL){
        return; 
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


// * POSTORDER TRAVERSAL ITERATIVE
void postorder_iterative(node* head){

}

// * CREATE A TREE FROM LEVEL ORDER TRAVERSAL
void createLevelOrder(node* &root){
    queue<node* > q;
    cout << "Enter data for the root: ";
    int d;
    cin >> d;
    root = new node(d);
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << ": ";
        int leftd;
        cin >> leftd;

        if(leftd != -1){
            temp->left = new node(leftd);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << " ";
        int rightd;
        cin >> rightd;

        if(rightd != -1){
            temp->right = new node(rightd);
            q.push(temp->right);
        }
    }

}

// * REVERSE LEVEL ORDER TRAVERSAL




int main(){
    // ! 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1  ,  1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    node *root = NULL;
    root = BuildTree(root);

    cout << "Printing Level Order Traversal" << endl;
    levelOrderTraversal(root);

    cout << "Inorder Traversal Recursive: ";
    inorder(root);
    cout << endl;

    cout << "Inorder Traversal Iterative: ";
    inorder_iterative(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

	cout << "Preorder Traversal: ";
    preorder_iterative(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    cout << "New Tree: " << endl;
    createLevelOrder(root);
    levelOrderTraversal(root);
}

