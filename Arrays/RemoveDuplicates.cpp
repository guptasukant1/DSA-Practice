#include<bits/stdc++.h>
using namespace std;

// $ Remove duplicates in place from sorted array

// $ Brute Force Approach
// $ TC: O(n + nlogn) | SC: O(n)
int removeDuplicates(int arr[], int n){
    set<int> st;
    for(int i = 0; i < n; i++) st.insert(arr[i]);
    int k = st.size();
    int j = 0;
    for(int x: st) arr[j++] = x;
    return k;
}


int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}
