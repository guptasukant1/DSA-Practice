#include<bits/stdc++.h>
using namespace std;

// $ Check for Balanced Parentheses
// $ TC: O(n) | SC: O(n)
bool isValid(string s){
    stack<char> st;
    for(auto it: s){
        if(it == '{' || it == '(' || it == '[') st.push(it);
        else{
            if(st.size() == 0) return false;
            char ch = st.top();
            st.pop();
            if( (ch == '(' && it == ')') || (ch == '{' && it == '}') || (ch == '[' && it == ']')) continue;
            else return false;
        }
    }
    return st.empty();
}

int main()
{
    string s="()[{}()]";
    if(isValid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}

