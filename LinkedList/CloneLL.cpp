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

// $ Brute Force Approach [Use map to store each node as the key:value -> access each value and set the next and random from the key's next and random]
// $ TC: O(2n) | SC: O(n + n)
Node* cloneLLBF(Node* head){
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

// $ Optimal Approach [create copy of nodes and insert between nodes -> set random and next pointers -> get the copied ll and reset next o original ll]
// $ TC: O() | SC: O()

void insertCopyInBetween(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        Node* nextEl = temp -> next;
        Node* copyNode = new Node(temp -> data);
        copyNode -> next = nextEl;
        temp -> next = copyNode;
        temp = nextEl;
    }
}

void connectRandom(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        Node* copyNode = temp -> next;
        if(temp -> random) copyNode -> random = temp -> random -> next; // * access the original node -> random to get the copied node
        else copyNode -> random = nullptr;
        temp = temp -> next -> next;
    }
}

Node* deepCopy(Node* head){
    Node* temp = head;
    Node* dum = new Node(-1);
    Node* res = dum;

    while(temp != nullptr){
        res -> next = temp -> next;
        res = res -> next;
        temp -> next = temp -> next -> next;
        temp = temp -> next;
    }
    return dum -> next;
}


Node* cloneLLOA(Node* head){
    if(!head) return nullptr;
    insertCopyInBetween(head); // * To insert the copy of each node in between 2 nodes
    connectRandom(head); // * Connect the random of the copied nodes
    return deepCopy(head); // * Get the copied LL
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

    // Node* clonedList = cloneLLBF(head);

    // cout << "\nCloned Linked List with Random Pointers:" << endl;
    // printClonedLinkedList(clonedList);

    Node* clonedList = cloneLLOA(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);}