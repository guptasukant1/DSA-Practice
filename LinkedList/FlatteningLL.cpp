#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Flatten a LL

class Node{
public:
    int data;
    Node* next;
    Node* child;

    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {};
    Node(int x, Node* nextNode, Node* childNode) : data(x), next(nextNode), child(childNode) {};
};


// $ Brute Force Approach
// $ TC: O[ (n * m) + (n * m * log(n * m)) + (n * m) ] | SC: O[ (n * m) + (n * m) ]
Node* convertArrToLL(vi &larr){
    Node* dum = new Node(-1);
    Node* temp = dum;
    for(int i = 0; i < larr.size(); i++){
        temp -> child = new Node(larr[i]);
        temp = temp -> child;
    }
    return dum -> child;
}

Node* flattenBF(Node* head){
    vi larr;
    Node* temp = head;

    while(head != nullptr){
        Node* temp = head;
        while(temp != nullptr){
            larr.push_back(temp -> data);
            temp = temp -> child;
        }
        head = head -> next;
    }
    sort(larr.begin(), larr.end());
    return convertArrToLL(larr);
}

// $ Optimal Approach
// $ TC: O(2 * n * m) | SC: O(1)
Node* mergeLL(Node* list1, Node* list2){
    Node* dum = new Node(-1);
    Node* temp = dum;

    while(list1 != nullptr && list2 != nullptr){
        if(list1 -> data < list2 -> data){
            temp -> child = list1;
            temp = list1;
            list1 = list1 -> child;
        }
        else{
            temp -> child = list2;
            temp = list2;
            list2 = list2 -> child;
        }
        temp -> next = nullptr;
    }
    if(list1) temp -> child = list1;
    else temp -> child = list2;

    if(dum -> child) dum -> child -> next = nullptr;
    return dum -> child;
}

Node* flattenOA(Node* head){
    if(head == nullptr || head -> next == nullptr) return head;
    Node* mergeHead = flattenOA(head -> next);
    head = mergeLL(head, mergeHead);
    return head;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

void printOriginalLinkedList(Node* head, int depth) {
    while (head != nullptr) {
        cout << head->data;

        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main() {
    Node* head = new Node(5);
    head->child = new Node(14);
    
    head->next = new Node(10);
    head->next->child = new Node(4);
    
    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);
    
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    Node* flattened = flattenBF(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    // Node* flattened = flattenOA(head);
    // cout << "\nFlattened linked list: ";
    // printLinkedList(flattened);
}