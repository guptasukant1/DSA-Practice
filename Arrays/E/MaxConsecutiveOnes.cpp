#include<bits/stdc++.h>
using namespace std;

// $ Max Consecutive Ones

// $ TC: O(n) | SC: O(1)
class Solution {
    public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int count = 0, maximum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) count++;
            else count = 0;
            maximum = max(maximum, count);
        }
        return maximum;
    }
};

int main() {
    vector < int > nums = { 1, 1, 0, 1, 1, 1 };
    Solution obj;
    int ans = obj.findMaxConsecutiveOnes(nums);
    cout << "The maximum consecutive 1's are " << ans;
}