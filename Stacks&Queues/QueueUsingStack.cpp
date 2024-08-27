#include<bits/stdc++.h>
using namespace std;

// $ Implement a Queue using 2 Stacks where TC of each op is O(n)
// $ TC: O(push: n, pop: n) | SC: O(2*n)

class Queue{
    stack<int> input, output;
    public:
    void Push(int x){
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }

        cout << "Element pushed is: " << x << endl;
        input.push(x);

        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }
    int Pop(){
        if(input.empty()){
            cout << "Stack Empty" << endl;
            exit(0);
        }
        int x = input.top();
        input.pop();
        return x;
    }
    int Top(){
        if(input.empty()){
            cout << "Stack Empty" << endl;
            exit(0);
        }
        return input.top();
    }
    int size(){
        return input.size();
    }
};

// $ Implement a Queue using 2 Stacks where TC of each op is O(1)
// $ TC: O(push: 1, pop: 1 (amortised), top: n) | SC: O(2*n)
class Queue1{
    stack<int> input, output;
    public:
    void Push(int x){
        cout << "The Element pushed is: " << x << endl;
        input.push(x);
    }
    int Pop(){
        if(output.empty()){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }
        int x = output.top();
        output.pop();
        return x;
    }
    int Top(){
        if(output.empty()){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    int size(){
        return output.size() + input.size();
    }
};

int main() {
    cout << "Queue 1: " << endl;
    Queue q;
    q.Push(3);
    q.Push(4);
    cout << "The element popped is " << q.Pop() << endl;
    q.Push(5);
    cout << "The top of the queue is " << q.Top() << endl;
    cout << "The size of the queue is " << q.size() << endl;

    cout << "Queue 2: " << endl;
    Queue1 q1;
    q1.Push(3);
    q1.Push(4);
    cout << "The element poped is " << q1.Pop() << endl;
    q1.Push(5);
    cout << "The top of the queue is " << q1.Top() << endl;
    cout << "The size of the queue is " << q1.size() << endl;

}