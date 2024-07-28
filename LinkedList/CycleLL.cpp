#include<bits/stdc++.h>
using namespace std;

// $ Detect a cycle in LL

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

// $ Brute Force Approach [Hashing]
// $ TC: O(n * 2 * logn) | SC: O(n)
bool detectLoop(Node* head){
    Node* temp = head;
    unordered_map<Node*, int> FreqMap;
    while(temp != nullptr){
        if(FreqMap.find(temp) != FreqMap.end()) return true;
        FreqMap[temp] = 1;
        temp = temp -> next;
    }
    return false;
}

// $ Optimal Approach [Tortoise and Hare] -> []
// $ TC: O() | SC: O()



int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; 

    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}