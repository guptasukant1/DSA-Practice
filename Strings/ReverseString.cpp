#include<bits/stdc++.h>
using namespace std;

int main(){
    // $ Reversing a string without stack

    // ? better approach to reverse a string is without using Stack but instead two pointers from start and from end.

    string s;
    cin >> s;
    // for(int i=0; (i<=s.length()/2 && j>s.length()/2 ); (i++ && j--)){
    for(int i=0; i<s.length()/2; i++){
        swap(s[i], s[s.length()-i-1]);
        // char temp;
        // temp = ch2;
        // ch2 = ch;
        // ch = temp;
    }
    cout << "Reversed String: " << s << endl;

    // $ Reversing a string using stack
    // ? Reversing a string using Stack TC: O(N) SC: O(N)

    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0;i<s.length(); i++){
        char ch = s[i];
        st.push(ch);
    }
    string ans = "";
    while(!st.empty()){
        char ch = st.top();
        ans.push_back(ch);
        st.pop();
    }
    cout << "Reversed String: " << ans << endl;
}