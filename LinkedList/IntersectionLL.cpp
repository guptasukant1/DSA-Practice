#include<bits/stdc++.h>
using namespace std;

// $ Find the intersection of 2 LL

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
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

// $ Brute Force Approach
// $ TC: O() | SC: O()
node* IntersectionBF(node* head1, node* head2){
    while(head2 != nullptr){
        node* temp = head1;
        while(temp != nullptr){
            if(temp == head2) return head2;
            temp = temp -> next;
        }
        head2 = head2 -> next;
    }
    return nullptr;
}


void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
}

int main() {
    node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    node* head1 = head;
    head = head->next->next->next;
    node* headSec = NULL;
    insertNode(headSec,3);
    node* head2 = headSec;
    headSec->next = head;

    cout<<"List1: "; printList(head1);
    cout<<"List2: "; printList(head2);

    node* answerNode = IntersectionBF(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->data<<endl;
}