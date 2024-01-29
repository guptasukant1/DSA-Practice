#include <bits/stdc++.h>
using namespace std;


// $ Circular singly LL
class csnode{
public:
    int data;
    csnode *next;

    csnode(int data){
        this->data = data;
        this->next = NULL;
    }

    ~csnode(){
        int value = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory freed for node: " << value << endl;
    }
};



// $ Insertion in circular singly
void insertNode(csnode* &tail, int element, int data){

    if(tail == NULL){
        // $ Empty List
        csnode *node1 = new csnode(data);
        tail = node1;
        node1->next = node1;
    }
    else{
        // $ Non Empty List
        csnode *curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        // $ Element found and curr is representing the node with data "element"
        csnode *temp = new csnode(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}


// $ Deletion in circular singly
void deleteNode(csnode* &tail, int value){

    // $ Empty List
    if(tail == NULL){
        cout << "List is Empty, check again" << endl;
        return;
    }
    else{
        // $ Non Empty

        csnode *prev = tail;
        csnode *curr = prev->next;


        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        // $ If only 1 node
        if(curr == prev){
            tail = NULL;
        }
        // $ >1 nodes
        else if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(csnode* &tail){

    csnode *temp = tail;
    if(tail == NULL){
        cout << "List is empty" << endl;
    }
    do{
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}


int main(){
    csnode *tail = NULL;

    insertNode(tail, 2, 3);
    print(tail);
    insertNode(tail, 3, 2);
    print(tail);
    insertNode(tail, 2, 9);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 10);
    print(tail);

    deleteNode(tail, 3);
    print(tail);
}