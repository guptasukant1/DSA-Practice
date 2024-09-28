#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Count Reverse Pairs. Reverse Pair: i < j && a[i] > 2 * a[j]

// $ Brute Force Approach
// $ TC: O(n^2) | SC: O(1)
int countPairs(vi &a, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > 2 * a[j]) count++;
        }
    }
    return count;
}

int team(vector <int> & skill, int n) {
    return countPairs(skill, n);
}

void merge(vi &a, int low, int mid, int high){
    vi temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high){
        if(a[left] <= a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(a[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(a[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        a[i] = temp[i - low];
    }
}

int countPairs(vi &a, int low, int mid, int high){
    int right = mid + 1;
    int count = 0;
    for(int i = low; i <= mid; i++){
        while((right <= high) && (a[i] > 2 * a[right])) right++;
        count += (right - (mid + 1));
    }
    return count;
}

int mergeSort(vi &a, int low, int high){
    int count = 0;
    if(low >= high) return count;
    int mid = (low + high) / 2;
    count += mergeSort(a, low, mid);
    count += mergeSort(a, mid + 1, high);
    count += countPairs(a, low, mid, high);
    merge(a, low, mid, high);
    return count;
}

int team1(vector <int> & skill, int n)
{
    return mergeSort(skill, 0, n - 1);
}

int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: " << cnt << endl;
    int cnt1 = team1(a, n);
    cout << "The number of reverse pair is: " << cnt1 << endl;
}
