#include <bits/stdc++.h>
using namespace std;

class reverseStack{
    public:
    // $ t=1; n=5; St={3 7 8 4 1}
    // $ The Reverse function pops the elements from the stack till base case reached.
    // $ Then the insertAtBottom function is called which first pushes the top element (1) into the now empty stack
    // $ Now, (4) will enter and will store the top element (1) in num, then it (4) itself gets pushed into the stack which was made empty
    // $ This continues for all remaining elements which reverses the order and stores them in num for each recursive call.
    // $ They then get pushed into the stack.

    void insertAtBottom(stack<int> &St, int x){
        if(St.empty()){
            St.push(x);
            return;
        }
        int num = St.top();
        St.pop();

        insertAtBottom(St, x);
        St.push(num);
    }

    void Reverse(stack<int> &St){
        if(St.empty()){
            return;
        }
        int x = St.top();
        St.pop();

        Reverse(St);
        insertAtBottom(St, x);
    }
};


int main(){
    // $ Reverse the Elements of a stack.


    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        stack<int> St;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            St.push(x);
        }
        reverseStack ob;
        ob.Reverse(St);
        vector<int> res;
        while (St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for (int i = res.size() - 1; i >= 0; i--)
        {
            cout << res[i] << " ";
        }

        cout << endl;
    }
}
