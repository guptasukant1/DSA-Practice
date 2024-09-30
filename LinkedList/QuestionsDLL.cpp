#include <bits/stdc++.h>
using namespace std;

class node{

public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// void reverseRecur(node *&head, node *&curr, node *&prev)
// {
//     // ! base case
//     if (curr == NULL)
//     {
//         head = prev;
//         return;
//     }
//     node *temp = curr->next;
//     reverseRecur(head, temp, curr);
//     curr->next = prev;
// }


node *reverse(node *&head){

    node *temp = NULL;
    node *curr = head;

    if(temp != NULL){
        head = temp->prev;
    }

    while(curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    return head;
}

void printList(node *head){
    node *temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}


int main(){
    int T, n, l, firstdata;
    cin >> T;

    while (T--){
        node *head = NULL, *tail = NULL;

        cin >> n;

        if (n != 0){
            cin >> firstdata;
            head = new node(firstdata);
            tail = head;
        }
        node *newtemp = head;
        for (int i = 1; i < n; i++){
            cin >> l;
            tail->next = new node(l);
            tail = tail->next;
            tail->prev = newtemp;
        }

        head = reverse(head);
        printList(head);
        cout << endl;
    }

    return 0;
}