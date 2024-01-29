#include <bits/stdc++.h>
using namespace std;

// $ Node Creation
class dlnode{
    public:
    int data;
    dlnode *prev;
    dlnode *next;

    dlnode(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~dlnode(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory freed for: " << val << endl;
    }
};

void insertAtHead(dlnode* &head, dlnode* &tail, int data){
    if(head==NULL){
        dlnode *temp = new dlnode(data);
        head = temp;
        tail = temp;
    }
    else{
        dlnode *temp = new dlnode(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtEnd(dlnode* &head, dlnode* &tail, int data){
    if(tail==NULL){
        dlnode* temp = new dlnode(data);
        tail = temp;
        head = temp;
    }
    else{
        dlnode *temp = new dlnode(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// void insertAfter(dlnode* &head, dlnode* &tail, int data, int pos){
//     dlnode *newNode = new dlnode(data);
//     if(pos == 1){
//         insertAtHead(head, tail, data);
//         return;
//     }
//     if (head == NULL) {
//         head = tail = newNode;
//         return;
//     }
//     dlnode *&temp = head;
//     int count = 1;
//     while(temp != NULL && count < pos){
//         temp = temp->next;
//         count++;
//     }
//     if(temp->next == NULL){
//         insertAtEnd(head, tail, data);
//         return;
//     }
//     newNode->next = temp->next;
//     if(temp -> next != NULL){
//         temp->next->prev = newNode;
//     }
//     temp->next = newNode;
//     newNode->prev = temp;
// }

void insertAfter(dlnode *&head, dlnode *&tail, int data, int pos)
{
    dlnode *newNode = new dlnode(data);

    if (pos <= 0) {
        cout << "Invalid position. Please provide a position greater than zero." << endl;
        return;
    }
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    if (head == nullptr)
    {
        head = tail = newNode;
        return;
    }

    dlnode *temp = head;
    int count = 1;
    while (temp->next != nullptr && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == nullptr){
        cout << "Position out of range. Inserting at the end." << endl;
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

void deleteNode(dlnode* &head, int pos){

    if (head == nullptr) {
        cout << "List is empty. Deletion not possible." << endl;
        return;
    }

    if(pos == 1){
        dlnode *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        dlnode *curr = head;
        dlnode *prev = NULL;

        int count = 1;
        while(count < pos){
            prev = curr;
            curr = curr->next;
            count++;
        }
        // prev->next = curr->next;
        // curr->next = NULL;
        if (curr == nullptr) {
            cout << "Position out of range. Deletion not possible." << endl;
            return;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(dlnode* head){
    dlnode *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(dlnode* head){
    int len = 0;
    dlnode *temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

int main(){

    dlnode *node1 = new dlnode(15);
    dlnode *head = node1;
    dlnode *tail = node1;
    // dlnode *head = NULL;
    // dlnode *tail = NULL;
    print(head);

    cout << getLength(head) << endl;

    insertAtHead(head, tail, 10);
    print(head);

    insertAtHead(head, tail, 5);
    print(head);

    insertAtHead(head, tail, 1);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    insertAtEnd(head, tail, 20);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    insertAfter(head, tail, 22, 1);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    insertAfter(head, tail, 25, 2);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    insertAfter(head, tail, 30, 9);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    deleteNode(head, 1);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    deleteNode(head, 5);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    deleteNode(head, 6);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

}