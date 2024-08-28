// $ Operations
// * 1 -> Push: To push an element in the Stack.
// * 2 -> Pop: To pop the topmost element from Stack.
// * 3 -> Peek: Views the Topmost element and selects it.
// * 4 -> isEmpty: Checkswhether the string is empty or not.

#include <bits/stdc++.h>
using namespace std;

// ? Stack Ops
class stacksol{

    public:

    int top;
    int size;
    int *arr;

    stacksol(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    // $ O(1)
    int push(int el){
        if(size-top>1){
            top++;
            arr[top] = el;
        }
        else{
            cout << "Stack Overflow" << endl;
            return 0;
        }
    }
    // $ O(1)
    void pop(){
        if(top>=0){
            top--;
        }
        else cout << "Stack Underflow" << endl;
    }
    // $ O(1)
    int peek(){
        if(top>=0 && top<size){
            return arr[top];
        }
        else{
            cout << "Stack Empty" << endl;
            return 0;
        }
    }
    // $ O(1)
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else return false;
    }

};

int main()
{
    stack<int> s;
    s.push(5);
    s.push(3);
    s.push(2);
    s.push(1);
    s.pop();
    cout << s.top() << endl;
    cout << s.empty() << endl;
    cout << s.size() << endl;


    int n;
    cout << "Enter the number of terms for stack: ";
    cin >> n;
    stacksol st(n);
    for(int i=0; i<n; i++){
        int v;
        cin >> v;
        st.push(v);
    }
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;
    if(st.isEmpty()){
        cout << "Stack is empty" << endl;
    }
    else cout << "Stack is not empty" << endl;

}


// !!!!!!!!!!!!!!!!!!!!

// $ STACK IMPLEMENTATION USING LINKED LIST

// !!!!!!!!!!!!!!!!!!!!

