#include <bits/stdc++.h>
using namespace std;

// $ Circular doubly LL
class cdnode
{
public:
    int data;
    cdnode *prev;
    cdnode *next;

    cdnode(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~cdnode()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory freed for node: " << value << endl;
    }
};

// $ Insertion at head in circular doubly
void insertAtHead(cdnode *&head, int data){

    if(head == NULL){
        // $ Empty List
        head = new cdnode(data);
        head->next = head;
        head->prev = head;
    }
    else{
        // $ Non Empty list
        cdnode *tail = head->prev;
        cdnode *temp = new cdnode(data);
        temp->next = head;
        temp->prev = tail;
        tail->next = head->prev = temp;
        head = temp;
    }
}

// $ Insertion at head in circular doubly
void insertAtEnd(cdnode* &head, int data){

    if(head == NULL){
        // $ Empty List
        cdnode* temp = new cdnode(data);
        temp->next = temp->prev = temp;
        head = temp;
    }
    else{
        // $ Non Empty List
        cdnode *tail = head->prev;
        cdnode *temp = new cdnode(data);
        temp->next = head;
        head->prev = temp;
        temp->prev = tail;
        tail->next = temp;
    }
}

void insertAfter(cdnode* &head, int data, int element){

    if(head == NULL){
        cdnode *insertNode = new cdnode(data);
        head = insertNode;
        head->next = head->prev = head;
    }
    else{
        cdnode *temp = head;
        while(temp->data != element && temp->next != head){
            temp = temp->next;
        }
        if(temp->data == element){
            cdnode *insertNode = new cdnode(data);
            insertNode->next = temp->next;
            insertNode->prev = temp;
            temp->next->prev = insertNode;
            temp->next = insertNode;

            if(temp == head->prev){
                head->prev = insertNode;
            }
        }else{
            cout << "Element not found" << endl;
        }
    }
}

void print(cdnode *&head){

    cdnode *temp = head;
    if (head == NULL){
        cout << "List is empty" << endl;
    }
    do{
        cout << head->data << " ";
        head = head->next;
    } while (head != temp);
    cout << endl;
}


int main(){

    cdnode *head = NULL;

    insertAtHead(head, 5);
    print(head);
    insertAtHead(head, 10);
    print(head);
    insertAtEnd(head, 15);
    print(head);
    insertAtEnd(head, 20);
    print(head);
    insertAfter(head, 8, 20);
    print(head);

}