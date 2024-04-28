#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long

// $ Kadane's Algorithm
// todo | Find the maximum sum subarray

ll maxSubArray(int arr[], int n)
{
    ll maximum = INT_MIN;
    ll sum = 0;
    int start = 0, s = -1, e = -1;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i;
        sum += arr[i];
        if (sum > maximum)
        {
            maximum = sum;
            s = start;
            e = i;
        }
        if (sum < 0)
            sum = 0;
    }

    cout << "SubArray: [";
    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]";

    return maximum;
}

int main()
{
    // vi arr;
    // ll n;
    // int x;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> x;
    //     arr.push_back(x);
    // }
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    ll subsum = maxSubArray(arr, n);
    cout << "SubArray Sum: " << subsum;
}