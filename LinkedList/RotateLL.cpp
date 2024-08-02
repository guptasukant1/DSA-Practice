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

// $ Brute Force Approach [Circular LL with moving last node k times to the start]
// $ TC: O(n * k) | SC: O(1)
node* rotateBF(node* head, int k){
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

// $ Optimal Approach [Circular LL]
// $ TC: O(n + (n - k % n)) | SC: O(1)
node* rotateOA(node* head, int k){
    if(head == nullptr || head -> next == nullptr) return head;
    node* temp = head;
    int len = 1;
    while(temp -> next != nullptr){
        len++;
        temp = temp -> next;
    }
    temp -> next = head;
    k = k % len;
    int end = len - k;
    while(end--) temp = temp -> next;
    head = temp -> next;
    temp -> next = nullptr;
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
    
    int k = 2;
    node* newHead = rotateBF(head,k);
    
    cout<<"After "<<k<<" iterations: ";
    printList(newHead);

    node* head1 = NULL;
    insertNode(head1,1);
    insertNode(head1,2);
    insertNode(head1,3);
    insertNode(head1,4);
    insertNode(head1,5);

    int k1 = 3;

    node* newHead1 = rotateOA(head1,k);
    
    cout<<"After "<<k<<" iterations: ";
    printList(newHead1);
}