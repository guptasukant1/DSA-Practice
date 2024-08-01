#include<bits/stdc++.h>
using namespace std;
#define stst stack<string>

// $ Reverse words in a given string

// $ Brute Force Approach
// $ TC: O(n) | SC: O(n) [n = no. of words]
string reverseSBF(string s){
    stst st;
    string str = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            st.push(str);
            str = "";
        }
        else str += s[i];
    }
    string ans = "";
    while(st.size() != 1){
        ans += st.top() + " ";
        st.pop();
    }
    ans += st.top();
    st.pop();
    return ans;
}

// $ Oprimal Approach
// $ TC: O() | SC: O()




int main(){
    string s = "TUF is great for interview preparation";
    cout << "Before:" << endl;
    cout << s << endl;
    s += " ";
    
    cout << "After" << endl;
    cout << reverseSBF(s);
}