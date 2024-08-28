#include<bits/stdc++.h>
using namespace std;

class redundantBrackets{
    // $
    public:
    bool findBrackets(string s){
        stack<char> st;
        for (int i = 0; i<s.length(); i++){
            char ch = s[i];
            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                st.push(ch);
            }
            else if (ch == ')')
            {
                bool isRedundant = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true) return true;
                st.pop();
            }
        }
        return false;
    }
};

int main(){

    // $ Check for Redundant Brackets

    int t;
    cin >> t;
    while (t--)
    {

        string s;
        cin >> s;

        redundantBrackets obj;
        int res = obj.findBrackets(s);

        cout << res << endl;
    }
}