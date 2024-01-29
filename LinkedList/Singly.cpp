#include <bits/stdc++.h>
using namespace std;

// ! Linked List is a dynamic array whose size can be changed at run time
// ! No memory is wasted. Insertion & Deletion is easy.

// $ Node creation
class slnode{
    public:
    int data;
    slnode *next;

    slnode(int data){
        this->data = data;
        this->next = NULL;
    }
    ~slnode(){
        // int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
    }
};


// $ TC: O(1) SC: O(1)
// * Insertion at head
void insertAtHead(slnode* &head, int data){

    slnode* temp = new slnode(data);
    temp->next = head;
    head = temp;
}


// $ TC: O(1) SC: O(1)
// * Insertion at tail
void insertAtTail(slnode* &tail, int data){
    slnode *temp = new slnode(data);
    tail->next = temp;
    tail = tail->next;
}


// $ TC: O(1) SC: O(1)
// * Insertion after a node
void insertAfter(slnode* &tail, slnode* &head , int pos, int data){

    if(pos==1){
        insertAtHead(head, data);
        return;
    }


    slnode *temp = head;
    int count = 1;
    while(count<pos-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        insertAtTail(tail, data);
        return;
    }

    slnode *newNode = new slnode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// * Print the Linked List
void print(slnode* &head){
    slnode* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(int pos, slnode* &head, slnode* tail){

    if(pos == 1){
        slnode *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        // free(temp);
    }


    else{
        slnode *curr = head;
        slnode *prev = NULL;
        int count = 1;
        while(count < pos){
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        tail = prev;
        cout << "tail" << tail->data << endl;
        // $ check again for the tail.
    }
    cout << "tail" << tail->data << endl;
}

int main(){
    slnode *node1 = new slnode(10);

    slnode *head = node1;
    slnode *tail = node1;
    print(head);

    int data;
    cout << "Enter the data for the node: ";
    cin >> data;

    insertAtHead(head, data);
    print(head);
    insertAtTail(tail, 15);
    print(head);

    int data1;
    cin >> data1;
    int pos;
    cin >> pos;
    insertAfter(tail, head, pos, data1);
    print(head);
    insertAtTail(tail, 20);
    print(head);

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    int pos1;
    cin >> pos1;
    deleteNode(pos1, head, tail);
    print(head);

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
}