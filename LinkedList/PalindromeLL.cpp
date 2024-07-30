#include<bits/stdc++.h>
using namespace std;

// $ Find if LL is Palindrome or not

class Node {
public:
    int data;   
    Node* next;      
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// $ Brute Force Approach [Extra DS to save each node's value]
// $ TC: O(2 * n) | SC: O(n)
bool isPalindrome(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp != nullptr){
        st.push(temp -> data);
        temp = temp -> next;
    }
    temp = head;
    while (temp != nullptr){
        if(temp -> data != st.top()) return false;
        st.pop();
        temp = temp-> next;
    }
    return true;
}

// $ Optimal Approach [Split LL and Reverse the parts with 2 heads and compare the values of both the lists] [Tortoise and Hare for mid element]
// $ TC: O() | SC: O()
Node* reverseLL(Node* head){
    if(head == nullptr || head -> next == nullptr) return head;
    Node* newHead = reverseLL(head -> next);
    Node* front = head -> next;
    front -> next = head;
    head -> next = nullptr;
    return newHead;
}

bool isPalindromeOA(Node* head){
    if(head == nullptr || head -> next == nullptr) return true;
    Node* slow = head;
    Node* fast = head;
    
    while(fast != nullptr && fast -> next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    Node* newHead = reverseLL(slow -> next);
    Node* first = head;
    Node* second = newHead;
    while(second != nullptr){
        if(first -> data != second -> data){
            reverseLL(newHead);
            return false;
        }
        first = first -> next;
        second = second -> next;
    }
    reverseLL(newHead);
    return true;
}


void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    if (isPalindromeOA(head)) {
        cout << "The linked list is a palindrome 1." << endl;
    } else {
        cout << "The linked list is not a palindrome 1." << endl;
    }

    return 0;
}