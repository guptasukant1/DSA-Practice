#include<bits/stdc++.h>
using namespace std;

// $ Remove Nth node from the end

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

// $ Brute Force Approach
// $ TC: O(l + (l - n)) | SC: O(1)
Node* deleteNode(Node* head, int n){
    if(head == nullptr) return nullptr;
    int count = 0;
    Node* temp = head;

    while(temp != nullptr){
        count++;
        temp = temp -> next;
    }

    if(count == n){
        Node* newHead = head -> next;
        delete(head);
        return newHead;
    }

    int res = count - n;
    temp = head;

    while(temp != nullptr){
        res--;
        if(res == 0) break;
        temp = temp -> next;
    }
    
    Node* delN = temp -> next;
    temp -> next = delN -> next;
    delete(delN);
    return head;
}

// $ Optimal Approach
// $ TC: O(n) | SC: O(1)
Node* deleteNodeOA(Node* head, int N){
    Node* fast = head;
    Node* slow = head;

    for(int i = 0; i < N; i++) fast = fast -> next;
    if(fast == nullptr) return head -> next;

    while(fast -> next != nullptr){
        fast = fast -> next;
        slow = slow -> next;
    }
    Node* delN = slow -> next;
    slow -> next = delN -> next;
    delete(delN);
    return head;
}

void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    head = deleteNode(head, N);
    printLL(head);
    cout << endl;
    head = deleteNodeOA(head, N);
    printLL(head);
}