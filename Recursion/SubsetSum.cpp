#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Sum of all Subsets
// $ TC: O(2^n + 2^nlog(2^n)) [each index has 2 opts and subsets + sort each subset] | SC: O(2^n)
class Solution {
    public:
    void subsetSumHelper(int index, vi &arr, int n, vi &ans, int sum){
        if(index == n){
            ans.push_back(sum);
            return;
        }
        subsetSumHelper(index + 1, arr, n, ans, sum + arr[index]); // * Consider the element in subset
        subsetSumHelper(index + 1, arr, n, ans, sum); // * Don't consider the elem
    }

    vi subsetSums(vi arr, int n){
        vi ans;
        subsetSumHelper(0, arr, n, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vi arr{3,1,2};
    Solution ob;
    vi ans = ob.subsetSums(arr, arr.size());
    sort(ans.begin(), ans.end());
    cout<<"The sum of each subset is "<<endl;
    for (auto sum: ans) {
        cout << sum << " ";
    }
    cout << endl;
}