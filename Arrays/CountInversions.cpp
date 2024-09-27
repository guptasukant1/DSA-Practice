#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
// $ Count the number of inversions in an array
// $ Inversion is a pair of indices i, j such that i < j and a[i] > a[j]

// $ Brute Force
// $ TC: O(N^2) | SC: O(1)
int countInversions(vi a){
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = i + 1; j < a.size(); j++){
            if(a[i] > a[j]) count++;
        }
    }
    return count;
}

// $ Optimal Approach[Merge Sort]
// $ TC: O(n*logn) | SC: O(n)
int merge(vi a, int low, int mid, int high){
    vi temp;
    int left = low;
    int right = mid + 1;

    int count = 0;

    while(left <= mid && right <= high){
        if(a[left] <= a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            count += (mid - left + 1);
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

    for(int i = low; i < high; i++){
        a[i] = temp[i - low];
    }
    return count;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // * left half
    cnt += mergeSort(arr, mid + 1, high); // * right half
    cnt += merge(arr, low, mid, high);  // * merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {
    return mergeSort(a, 0, n - 1);
}

int main(){
    vector<int> a = {5, 4, 3, 2, 1};
    vector<int> a1 = {5, 4, 3, 2, 1};
    int n = a1.size();
    int cnt = countInversions(a);
    cout << "The number of inversions is: " << cnt << endl;
    int cnt1 = numberOfInversions(a1, n);
    cout << "The number of inversions is: " << cnt1 << endl;
}