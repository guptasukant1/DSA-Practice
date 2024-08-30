#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Brute Force: Implement 2 loops i = 0 -> n - 1 and j = i + 1 -> n - 1, compare ith and jth element to set the NGE into ith place.

// $ Optimal Approach: 
// $ TC: O(n) | SC: O(n)
// * Use stack, start from RHS, move while pushing elems into stack. If next elem is smaller, push into arr and the NGE of the current elem would be curr stack top
// * If any greater elem comes, pop the smaller ones in stack and then we will have the NGE in the stack top.

class Solution{
    public:
    vi nextGreaterElements(vi &nums){
        int n = nums.size();
        vi NGE(n, -1);
        stack<int> st;
        for(int i = 2 * n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i % n]) st.pop();
            if(i < n){ // * To obtain only the first half of the copied array, i.e. the original array only
                if(!st.empty()) NGE[i] = st.top();
            }
            st.push(nums[i % n]);
        }
        return NGE;
    }
};

int main() {
    Solution obj;
    vector < int > v {5,7,1,2,6,0};
    vector < int > res = obj.nextGreaterElements(v);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}