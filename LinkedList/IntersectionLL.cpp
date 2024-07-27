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

// $ Brute Force Approach [compares each element of both lists]
// $ TC: O(m*n) | SC: O(1)
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

// $ Hashing Approach
// $ TC: O(n + m) | SC: O(n)
node* IntersectionHA(node* head1, node* head2){
    unordered_set<node*> uset;
    while(head1 != nullptr){
        uset.insert(head1);
        head1 = head1 -> next;
    }
    while(head2 != nullptr){
        if(uset.find(head2) != uset.end()) return head2;
        head2 = head2 -> next;
    }
    return nullptr;
}

// $ Optimal Approach 1 [Length Difference]
// $ TC: O() | SC: O()
int getDiff(node* head1, node* head2){
    int len1 = 0, len2 = 0;
    while(head1 || head2){
        if(head1){
            len1++;
            head1 = head1 -> next;
        }
        if(head2){
            len2++;
            head2 = head2 -> next;
        }
    }
    return len1 - len2;
}

node* IntersectionOA(node* head1, node* head2){
    int diff = getDiff(head1, head2);
    if(diff < 0) while(diff++ != 0) head2 = head2 -> next;
    else while(diff-- != 0) head1 = head1 -> next;
    while(head1){
        if(head1 == head2) return head1;
        head2 = head2 -> next;
        head1 = head1 -> next;
    }
    return head1;
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

    node* answerNode = IntersectionBF(head1, head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->data<<endl;

    node* answerNode1 = IntersectionHA(head1, head2);
    if(answerNode1 == NULL)
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode1->data<<endl;
    
    node* answerNode2 = IntersectionOA(head1, head2);
    if(answerNode2 == NULL)
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode2->data<<endl;
}