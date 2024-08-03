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

    return 0;
}