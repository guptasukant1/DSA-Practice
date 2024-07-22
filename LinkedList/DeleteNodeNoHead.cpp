#include<bits/stdc++.h>
using namespace std;

// $ Delete a node from LL without head reference
// | Take the node to be deleted and access its RHS. We first need to get the node using the head of the LL.
// | and then delete the node by copying the value of the next node to the current node, and breaking the link b/w the 2 and pushing the link to next node. 

class node {
public:
    int num;
    node* next;
    node(int a) {
        num = a;
        next = NULL;
    }
};

void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

node* getNode(node* head, int val){
    while(head -> num != val) head = head -> next;
    return head;
}

void deleteNode(node* t){
    t -> num = t -> next -> num;
    t -> next = t -> next -> next;
    return;
}

void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<"\n";
}

int main() {
    node* head = NULL;
    //inserting node
    insertNode(head,1);
    insertNode(head,4);
    insertNode(head,2);
    insertNode(head,3);
    //printing given list
    cout<<"Given Linked List:\n";
    printList(head);
    node* t = getNode(head,2);
    //delete node
    deleteNode(t);
    //list after deletion operation
    cout<<"Linked List after deletion:\n";
    printList(head);
    return 0;
}