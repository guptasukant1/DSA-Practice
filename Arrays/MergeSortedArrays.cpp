#include <bits/stdc++.h>
using namespace std;
#define ll long long

// $ Merge two sorted arrays without using extra space
// $ Brute-Force Approach
// $ TC: O(n + m) + O(n + m)

void mergeArr(ll arr1[], ll arr2[], int n, int m)
{
    ll arr3[n + m];
    int l = 0, r = 0, k = 0;

    while (l < n && r < m)
    {
        if (arr1[l] <= arr2[r])
        {
            arr3[k] = arr1[l];
            l++, k++;
        }
        else
        {
            arr3[k] = arr2[r];
            r++, k++;
        }
    }

    while (l < n)
    {
        arr3[k++] = arr1[l++];
    }

    while (r < m)
    {
        arr3[k++] = arr2[r++];
    }

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            arr1[i] = arr3[i];
        else
            arr2[i - n] = arr3[i];
    }
}

// $ Optimal Approach 1
// $ O(min(n, m)) + O(n*logn) + O(m*logm)[swap + sort(arr1) + sort(arr2)]
void mergeArr1(ll arr1[], ll arr2[], int n, int m){
    int l = n - 1, r = 0;

    while(l >= 0 && r < m){
        if(arr1[l] > arr2[r]){
            swap(arr1[l], arr2[r]);
            l--, r++;
        }
        else
            break;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

// $ LEETCODE
void mergeA(ll arr1[], ll arr2[], int n, int m){
    int i = n - 1, j = m - 1, k = m + n - 1;

    while(j >= 0){
        if(i >= 0 && arr1[i] > arr2[j]){
            arr1[k--] = arr1[i--];
        }
        else
            arr1[k--] = arr2[j--];
    }
}


int main()
{
    ll arr1[] = {1, 4, 8, 10};
    ll arr2[] = {2, 3, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    // mergeArr(arr1, arr2, n, m);
    mergeArr1(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}