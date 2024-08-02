#include<bits/stdc++.h>
using namespace std;

// $ Rotate a LL

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
    return;
}

node* rotateRight(node* head, int k){
    if(head == nullptr || head -> next == nullptr) return head;

    for(int i = 0; i < k; i++){
        node* temp = head;
        while(temp -> next -> next != nullptr) temp = temp -> next;
        node* end = temp -> next;
        temp -> next = nullptr;
        end -> next = head;
        head = end;
    }
    return head;
}

void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    } 
    cout<<head->num<<endl;
    return;
}

int main() {
    node* head = NULL;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    
    cout<<"Original list: ";
    printList(head);
    
    int k = 3;
    node* newHead = rotateRight(head,k);
    
    cout<<"After "<<k<<" iterations: ";
    printList(newHead);
}