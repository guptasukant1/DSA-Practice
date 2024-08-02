#include<bits/stdc++.h>
using namespace std;

// $ Starting point of loop in LL

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

// $ Brute Force Approach [Unordered Map -> add entry to the map and check for reps, if found, loop exists at rep node]
// $ TC: O(n) | SC: O(n)
Node* detectLoop(Node* head){
    Node* temp = head;
    unordered_map<Node*, int> NodeMap;
    while(temp != nullptr){
        if(NodeMap.count(temp) != 0) return temp; // * Checks if the node exists in map or not
        NodeMap[temp] = 1; // * Add entry and val to map
        temp = temp -> next; 
    }  
    return nullptr;
}

// $ Optimal Approach [T&H algo -> find meeting point and reset the slow and move both by one till meet]
// $ TC: O(n) | SC: O(1)
Node* detectLoopOA(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast -> next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1-> next = node2;
    Node* node3 = new Node(3);
    node2-> next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4-> next = node5;

    node5->next = node2;

    Node* head = node1;

    Node* loopStartNode = detectLoop(head);

    if (loopStartNode) {
        cout << "Loop detected. Starting node of the loop is: " << loopStartNode->data << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }
    
    Node* loopStartNode1 = detectLoopOA(head);

    if (loopStartNode1) {
        cout << "Loop detected. Starting node of the loop is: " << loopStartNode1->data << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }
}