#include<bits/stdc++.h>
using namespace std;

// $ Reverse a LL in group of size k

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

// $ Optimal Approach
// $ TC: O() | SC : O()
Node* reverseList(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        Node* front = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* getKthNode(Node* temp, int k){
    k --;
    while(temp != nullptr && k > 0){
        k--;
        temp = temp -> next;
    }
    return temp;
}

Node* kReverse(Node* head, int k){
    Node* temp = head;
    Node* prevLast = nullptr;

    while(temp != nullptr){
        Node* KthNode = getKthNode(temp, k);
        if(KthNode == nullptr){
            if(prevLast) prevLast -> next = temp;
            break;
        }
        Node* nextNode = KthNode -> next;
        KthNode -> next = nullptr;
        reverseList(temp);
        if(temp == head) head = KthNode; // * For 1st K group
        else prevLast -> next = KthNode;

        prevLast = temp;
        temp = nextNode;
    }
    return head;
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
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = kReverse(head, 4);

    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}