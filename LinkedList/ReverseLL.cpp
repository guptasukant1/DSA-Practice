#include <bits/stdc++.h>
using namespace std;

// $ Reversing a Linked List

class node{
    public:
    int data;
    node* next;
    node(int data, node* next){
        this->data = data;
        this->next = next;
    }
    node(int data){
        this->data = data;
        next = nullptr;
    }
};

node* ReverseLL(node* head){
    node* temp = head;
    stack<int> st;
    while (temp != nullptr){
        st.push(temp->data);
    }
    
}

int main(){
    node* head = new node(1);
    head->next = new node(3);
    head->next->next = new node(2);
    head->next->next->next = new node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = ReverseLL(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);
}