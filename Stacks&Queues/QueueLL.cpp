#include<bits/stdc++.h>
using namespace std;

// $ Queue using LL

class Node
{
 public: 
    int data;
    Node *next;
    Node(int x){
       data = x;
       next = nullptr;
    }
};

class Queue{
public:
    Node* front, *rear;
    int size;
    Queue(){
        size = 0;
        front = nullptr;
        rear = nullptr;
    }
    bool Empty(){
        return front == nullptr;
    }
    int Peek(){
        if(Empty()) {
            cout << "Queue is Empty";
            return -1;
        }
        else return front -> data;
    }
    void Enqueue(int x){
        Node* temp = new Node(x);
        if(temp == nullptr) cout << "Queue Full" << endl;
        else{
            if(front == nullptr){
                front = temp;
                rear = temp;
            }
            else {
                rear -> next = temp;
                rear = temp;
            }
        }
        cout << temp -> data << " Inserted" << endl;
        size++;
    }
    void Dequeue(){
        if(front == nullptr) cout << "Queue is Empty" << endl;
        else{
            Node* temp = front;
            cout << front -> data << " Removed from the Queue" << endl;
            front = front -> next;
            delete temp;
            size--;
        }
    }
};


int main(){
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout<<"The size of the Queue is "<<Q.size<<endl;
    cout<<"The Peek element of the Queue is "<<Q.Peek()<<endl;
}   
