#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Merge Two Sorted Linked List

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
// $ TC: O(n1 + n2 + nlog(n) + n) | SC: O(n + n)
Node* ConvertALL(vi &arr){
    Node* dum = new Node(-1);
    Node* temp = dum;
    for(int i = 0; i < arr.size(); i++){
        temp -> next = new Node(arr[i]);
        temp = temp -> next;
    }
    return dum -> next;
}

Node* SortLL(Node* list1, Node* list2){
    vi arr;
    Node* temp1 = list1;
    Node* temp2 = list2;

    while(temp1 != nullptr){
        arr.push_back(temp1 -> data);
        temp1 = temp1 -> next;
    }

    while(temp2 != nullptr){
        arr.push_back(temp2 -> data);
        temp2 = temp2 -> next;
    }
    sort(arr.begin(), arr.end());
    Node* head = ConvertALL(arr);
    return head;
}




void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->data << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}

int main() {
    // Example Linked Lists
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Node* mergedList = SortLL(list1, list2);

    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}