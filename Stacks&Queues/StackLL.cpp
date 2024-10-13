#include<bits/stdc++.h>
using namespace std;

// $ Stack using LL
// $ TC: O(1) | SC: O(n)

struct Node{
    int data;
    Node* next;
    int size;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

struct Stack{
    Node* top;
    int size;
    Stack(){
        top = nullptr;
        size = 0;
    }
    void SPush(int x){
        Node* element = new Node(x);
        element -> next = top;
        top = element;
        cout << "Pushed: " << element -> data << endl;
        size++;
    }
    int SPop(){
        if(!top) return -1;
        int NData = top -> data;
        Node* temp = top;
        top = top -> next;
        delete temp;
        size--;
        return NData;
    }
    int SSize(){
        return size;
    }
    bool SIsEmpty(){
        return top == nullptr;
    }
    int SPeak(){
        if(!top) return -1;
        return top -> data;
    }
    void printStack() {
        Node * current = top;
        while (current != NULL) {
            cout << current -> data << " ";
            current = current -> next;
        }
    }
};

int main(){
    Stack s;
    s.SPush(10);
    s.SPush(11);
    cout << "Element popped: " << s.SPop() << "\n";
    cout << "Stack size: " << s.SSize() << "\n";
    cout <<"Stack empty or not? "<<s.SIsEmpty()<<"\n";
    cout << "stack's top element: " << s.SPeak() << "\n";
}