#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Union of 2 Sorted Arrays

// $ BFA
// $ TC: O((m+n)log(m+n)) | SC: O(n+m)
vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
    map<int, int> mpp;
    vi Union;
    for(int i = 0; i < n; i++) {
        mpp[arr1[i]]++;
    }
    for(int i = 0; i < m; i++) {
        mpp[arr2[i]]++;
    }
    for(auto it: mpp) {
        Union.push_back(it.first);
    }
    return Union;
}

// $ Better Approach
// $ TC: O((m+n)log(m+n)) | SC: O(m+n)
vector<int> FindUnionBeA(int arr1[], int arr2[], int n, int m) {
    set<int> st;
    vi Un;
    for(int i = 0; i < n; i++) {
        st.insert(arr1[i]);
    }
    for(int i = 0; i < m; i++) {
        st.insert(arr2[i]);
    }
    for(auto it: st) {
        Un.push_back(it);
    }
    return Un;
}

// $ OA
// $ TC: O(m+n) | SC: O(1)
vi FindUnionOA(int arr1[], int arr2[], int n, int m) {
    vi Un;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(arr1[i] <= arr2[j]) {
            if(Un.size() == 0 || Un.back() != arr1[i]) Un.push_back(arr1[i]);
            i++;
        }
        else {
            if(Un.size() == 0 || Un.back() != arr2[j]) Un.push_back(arr2[j]);
            j++;
        }
    }
    while(i < n) {
        if(Un.back() != arr1[i]) Un.push_back(arr1[i]);
        i++;
    }
    while(j < m) {
        if(Un.back() != arr2[j]) Un.push_back(arr2[j]);
        j++;
    }
    return Un;
}

int main() {
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector < int > Union = FindUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto & val: Union)
    cout << val << " ";

    cout << endl;
    
    vector < int > Union1 = FindUnionBeA(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto & val: Union1)
    cout << val << " ";

    cout << endl;
    
    vector < int > Union2 = FindUnionOA(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto & val: Union2)
    cout << val << " ";
}