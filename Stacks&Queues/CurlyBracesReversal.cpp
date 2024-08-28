#include<bits/stdc++.h>
using namespace std;

int countRev(string s){
    if(s.length()%2!=0) return -1;

    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if(ch == '{') st.push(ch);

        else {
            if(st.top()=='{' && !st.empty()){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    int closing = 0, opening = 0;
    while(!st.empty()){
        if(st.top() == '{') opening++;
        else closing++;

        st.pop();
    }
    int ans = (closing + 1) / 2 + (opening + 1) / 2;
    return ans;
}

int main(){

// $ Count curly braces reversals


    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << countRev(s) << '\n';
    }

}