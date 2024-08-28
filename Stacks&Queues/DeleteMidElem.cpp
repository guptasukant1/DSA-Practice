#include<bits/stdc++.h>
using namespace std;

class deleteMiddleElement
{
    // $ Delete middle element via recursion. Iterative method not able to handle large data.
    // $ Correct the iterative method
    public:

    // void solve(stack<int> &s, int count, int sizeOfStack){
    //     if (count == sizeOfStack / 2)
    //     {
    //         s.pop();
    //         return;
    //     }

    //     int x = s.top();
    //     cout << "TOP: " << s.top()<<endl;
    //     s.pop();
    //     cout<<"count: " << count << endl;
    //     solve(s, count + 1, sizeOfStack);
    //     cout << "x: " << x <<endl;
    //     s.push(x);
    //     cout << "pushed"<<endl;
    // }

    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        stack<char> s1;
        int count = 0;
        int mid = sizeOfStack / 2;
        while (count < mid)
        {
            char x = s.top();
            s.pop();
            s1.push(x);
            count++;
        }
        s.pop();
        while (!s1.empty())
        {
            s.push(s1.top());
            s1.pop();
        }
        // int count = 0;
        // solve(s, count, sizeOfStack);
    }

};


int main(){

    // $ Deleting middle element

    int t;
    cin >> t;

    while (t--)
    {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++)
        {
            int x;
            cin >> x;
            myStack.push(x);
        }

        deleteMiddleElement dme;
        dme.deleteMid(myStack, myStack.size());
        while (!myStack.empty())
        {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }

}