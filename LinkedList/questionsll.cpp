#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void reverseRecur(node* &head, node* &curr, node* &prev){
    // ! base case
    if(curr == NULL){
        head = prev;
        return;
    }
    node* temp = curr->next;
    reverseRecur(head, temp, curr);
    curr->next = prev;
}

// $ TC: O(n)
// $ SC: O(n)
node* reverse1(node* &head){
    node* curr = head;
    node *prev = NULL;
    reverseRecur(head, curr, prev);
    return head;
}

// $ TC: O(n)
// $ SC: O(n)
node* reverse2(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* newhead = reverse2(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

node* reverse(node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node *prev = NULL;
    node *curr = head;
    node *temp = NULL;
    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return head;
}

void printList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " " ;
        temp = temp->next;
    }

}

// $ Hare and Tortoise strategy, slow and fast pointer move at different steps. The fast pointer moves at twice the speed of the slow pointer.
// $ The slow pointer will reach the middle element when the fast pointer reaches the end of the linked list.
node* middleElement(node *head){
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// $ Reverse LL in groups of k
// todo | Reverse the first sub-list of size k. While reversing keep track of the next node and previous node.
// todo | Let the pointer to the next node be next and pointer to the previous node be prev.




int main(){

    int T, n, l, firstdata;
    cin >> T;

    while (T--)
    {
        node *head = NULL, *tail = NULL;

        cin >> n;

        if (n != 0)
        {
            cin >> firstdata;
            head = new node(firstdata);
            tail = head;
        }

        for (int i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new node(l);
            tail = tail->next;
        }

        node *x = middleElement(head);
        cout << x << endl;
        head = reverse2(head);
        printList(head);
        cout << endl;
    }
    return 0;
}

