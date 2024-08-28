#include<bits/stdc++.h>
using namespace std;

class insertAtEnd{
    public:
    // $ Insert element at end of stack

    void solve(stack<int> &st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int num = st.top();
        st.pop();
        solve(st, x);
        st.push(num);
    }

    stack<int> insert(stack<int> &st, int x){
        solve(st, x);
        return st;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin >> n;
        cin >> x;
        stack<int> st;
        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            st.push(a);
        }
        insertAtEnd ob1;
        stack<int> tmp = ob1.insert(st, x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());
            tmp.pop();
        }
        reverse(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            cout << v[i];
            if(i!=v.size()-1) cout << "";
        }
        cout << endl;
    }
}