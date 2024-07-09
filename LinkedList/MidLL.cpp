#include<bits/stdc++.h>
using namespace std;

// $ Middle Element of Linked List

class Node {
    public:
    int data;
    Node* next;
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};


// $ Brute Force Approach
// $ TC: O(n + n / 2) | SC: O(1)
Node* findMiddle(Node* head){
    if(head == nullptr || head -> next == nullptr) return head;
    Node* temp = head;
    int count = 0;

    while(temp != nullptr){
        count++;
        temp = temp -> next;
    }
    int mid = (count / 2) + 1;
    temp = head;

    while(temp != nullptr){
        mid--;
        if(mid == 0) break;

        temp = temp -> next;
    }
    return temp;
}

// $ Optimal Approach
// $ TC: O() | SC: O()


int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(5);

    // Find the middle node
    Node* middleNode = findMiddle(head);

    // Display the value of the middle node
    cout << "The middle node value is: " << middleNode->data << endl;

    return 0;
}