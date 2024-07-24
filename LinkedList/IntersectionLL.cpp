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
