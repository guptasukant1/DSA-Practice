#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Move all zeroes to end while move rest to start

// $ BFA
// $ TC: O(n + x + (n-x)) ~ O(2n) | SC: O(n)
vi moveZeros(int n, vi arr) {
    vi temp;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) temp.push_back(arr[i]);
    }
    for(int i = 0; i < temp.size(); i++) {
        arr[i] = temp[i];
    }
    for(int i = temp.size(); i < n; i++) {
        arr[i] = 0;
    }
    return arr;
}

// $ OA
// $ TC: O(n) | SC: O(1)
vi moveZeroesOA(int n, vi arr) {
    int j = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            j = i;
            break;
        }
    }

    if(j == -1) return arr;
    
    for(int i = j + 1; i < n; i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main() {
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZeros(n, arr);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}