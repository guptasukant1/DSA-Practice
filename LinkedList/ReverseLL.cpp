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

// $ Brute Force Approach [Stack]
// $ TC: O(2n) | SC: O(n)
node* ReverseLL(node* head){
    node* temp = head;
    stack<int> st;
    while (temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!= nullptr){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

// $ Optimal Approach 1 [In-place reversal [Iterative]]
// $ TC: O(n) | SC: O(1)
node* ReverseLLOA1(node* head){
    node* temp = head;
    node* prev = NULL;
    while(temp != nullptr){
        node* front = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

void printLinkedList(node* head){
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    node* head = new node(1);
    head->next = new node(3);
    head->next->next = new node(2);
    head->next->next->next = new node(4);

    cout << "Original Linked List: ";
    printLinkedList(head);
    head = ReverseLL(head);
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    cout << "Original Linked List: ";
    printLinkedList(head);
    head = ReverseLLOA1(head);
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    cout << "Original Linked List: ";
    printLinkedList(head);
    head = ReverseLLOA1(head);
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    
}