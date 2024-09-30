#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Find Duplicate in Array
// $ Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

// $ Brute Force Approach
// $ TC: O(n*logn + n) | SC: O(1)
int findDuplicateBF(vi &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            return arr[i];
    }
    return 0;
}

// $ Better Approach[freq array]
// $ TC: O(n) | SC: O(n)
// ! Best runtime [due to hashing, however SC is O(n) due to hash array / freq array]
int findDuplicateB(vi &arr)
{
    int n = arr.size();
    int freq[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] == 0)
            freq[arr[i]] += 1;
        else
            return arr[i];
    }
    return 0;
}

// $ Optimal Approach
// $ TC: O(n) | SC: O(1)
int findDuplicateO(vi &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main()
{
    vi arr = {1, 3, 4, 2, 3};
    vi arr1 = {1, 3, 4, 2, 1};
    vi arr2 = {1, 3, 4, 2, 4};
    cout << "The duplicate element is: " << findDuplicateBF(arr) << endl;
    cout << "The duplicate element is: " << findDuplicateBF(arr1) << endl;
    cout << "The duplicate element is: " << findDuplicateBF(arr2) << endl;
}