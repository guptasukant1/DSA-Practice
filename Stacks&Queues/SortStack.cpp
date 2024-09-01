#include<bits/stdc++.h>
using namespace std;

// $ Sort the elements of a stack

class sortStack{
    public:
    void sortedInsert(stack<int> &s, int num){
        if(s.empty() || ( !s.empty() && s.top()<num )){
            s.push(num);
            return;
        }
        int n = s.top();
        s.pop();

        sortedInsert(s, num);
        s.push(n);
    }

    void sorting(stack<int> &s){
        if(s.empty()) return;

        int num = s.top();
        s.pop();

        sorting(s);
        sortedInsert(s, num);
    }
};

int main(){
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
        sortStack ob;
        ob.sorting(St);
        while (!St.empty())
        {
            printf("%d ", St.top());
            St.pop();
        }
        printf("\n");
        cout << endl;
    }
}