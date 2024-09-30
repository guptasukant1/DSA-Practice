#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Sort an array of 0s, 1s and 2s
// | Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

// $ Brute Force: sort them directly, via funtion or loops
// $ Time complexity: O(nlogn)

// $ Better: Have 3 counters for 0s, 1s, and 2s and use them to count frequencies of each, replace the number of items in array till the frequency with the desired number
// $ TC: O(n) + O(n)

// $ Optimal: Dutch National Flag Algorithm

void sort012(vi &nums){
    int n = nums.size();
    int l = 0, m = 0, h = n - 1;

    while (m <= h){
        if (nums[m] == 0){
            swap(nums[l], nums[m]);
            l++;
            m++;
        }
        else if (nums[m] == 1) m++;
        
        else{
            swap(nums[m], nums[h]);
            h--;
        }
    }
}

int main()
{
    vector<int> arr = {0, 2, 1, 2, 0, 1, 2, 0, 2, 1, 1, 0};
    int n = arr.size();
    cout << "Before sorting:" << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    sort012(arr);
    cout << "\nAfter sorting:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}