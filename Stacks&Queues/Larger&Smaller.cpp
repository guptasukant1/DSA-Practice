#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // $ Next larger (first larger to the right) element of each element in an array/vector using stacks
    // $ TC: O(N) SC: O()
    vector<long long> nextLargerElement(vector<long long> abc, int n)
    {
        stack<long long int> st;
        vector<long long int> ans(n);
        st.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && abc[i] >= st.top())
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(abc[i]);
        }
        return ans;
    }
    // $ Previous larger (first larger to the left) element of each element in an array/vector using stacks
    // $ TC: O(N) SC: O()
    vector<long long> previousLargerElement(vector<long long> abc, int n)
    {
        stack<long long int> st;
        vector<long long int> ans(n);
        st.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && abc[i] >= st.top())
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(abc[i]);
        }
        return ans;
    }

    // $ Next smaller (first smaller to the right) element of each element in an array/vector using stacks
    // $ TC: O(N) SC: O()
    vector<long long> nextSmallerElement(vector<long long> abc, int n)
    {
        stack<long long int> st;
        vector<long long int> ans(n);
        st.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && abc[i] <= st.top())
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(abc[i]);
        }
        return ans;
    }

    // $ Previous smaller (first smaller to the left) element of each element in an array/vector using stacks
    // $ TC: O(N) SC: O()
    vector<long long> previousSmallerElement(vector<long long> abc, int n)
    {
        stack<long long int> st;
        vector<long long int> ans(n);
        st.push(-1);
        for (int i = 0; i <= n-1; i++)
        {
            while (st.top() != -1 && abc[i] <= st.top())
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(abc[i]);
        }
        return ans;
    }
};

int main(){

    // $ Next/previous larger and smaller elements of each element


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> abc(n);
        for (int i = 0; i < n; i++)
            cin >> abc[i];
        Solution obj;
        vector<long long> res = obj.nextLargerElement(abc, n);
        vector<long long> res1 = obj.nextSmallerElement(abc, n);
        vector<long long> res2 = obj.previousSmallerElement(abc, n);
        cout << "next larger: " << endl;
        for (long long i : res)
            cout << i << " ";
        cout << endl;
        cout << "next smaller: " << endl;
        for (long long i : res1)
            cout << i << " ";
        cout << endl;
        cout << "previous smaller: " << endl;
        for (long long i : res2)
            cout << i << " ";
        cout << endl;
    }
    return 0;

}