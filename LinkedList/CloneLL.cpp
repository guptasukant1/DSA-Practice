#include<bits/stdc++.h>
using namespace std;

// $ Clone LL with next and random pointer

class Node {
public:
    int data;           
    Node *next;        
    Node *random;       

    Node() : data(0), next(nullptr), random(nullptr){}; 
    Node(int x) : data(x), next(nullptr), random(nullptr) {} 
    Node(int x, Node *nextNode, Node *randomNode) : data(x), next(nextNode), random(randomNode) {}  
};



Node* cloneLL(Node* head){
    Node* temp = head;
    unordered_map<Node*, Node*> mpp;

    while(temp != nullptr){
        Node* newNode = new Node(temp -> data);
        mpp[temp] = newNode;
        temp = temp -> next;
    }

    temp = head;
    while(temp != nullptr){
        Node* copyNode = mpp[temp];
        copyNode -> next = mpp[temp -> next];
        copyNode -> random = mpp[temp -> random];
        temp = temp -> next;
    }
    return mpp[head];
}


void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
        head = head->next;  
    }
}

int main() {
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    Node* clonedList = cloneLL(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}