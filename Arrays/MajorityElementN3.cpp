#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define miip map<int, int>
#define ll long long
#define vii vector<vector<int>>

// $ Majority Element in an array is an element that appears more than n/3 times in the array

// $ Brute-Force Approach
// $ TC: O(n^2) | SC: O(1) [despite list as only 2 elements stored]
vi majelem(vi v){
    int n = v.size();
    vi ts;
    for (int i = 0; i < n; i++){
        if(ts.size() == 0 || ts[0] != v[i]){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(v[i] == v[j]) count++;
            }
            if(count > (n / 3)) ts.push_back(v[i]);
        }
        if(ts.size() == 2) break;
    }
    return ts;
}


// $ Better Approach [Hash Maps]
// $ TC: O() | SC: O()
vi majelemBe(vi v){
    int n = v.size();
    vi ts;
    miip mpp;
    // * least occ of maj element
    int mini = int(n / 3) + 1;
    for(int i = 0; i < n; i++){
        mpp[v[i]]++;
        if(mpp[v[i]] == mini) ts.push_back(v[i]);
        if(ts.size() == 2) break;
    }
    return ts;
}

// $ Optimal Approach [Modified Moore's voting algo]
// $ TC: O() | SC: O()
vi majelemOA(vi v){
    int n = v.size();
    // | There will be 2 majority elements at max for any size of the array.
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;

    for(int i = 0; i < n; i++){
        if(cnt1 == 0 && el2 != v[i]){
            cnt1 = 1;
            el1 = v[i];
        }
        else if(cnt2 == 0 && el1 != v[i]){
            cnt2 = 1;
            el2 = v[i];
        }
        else if(v[i] == el1) cnt1++;
        else if(v[i] == el2) cnt2++;
        else cnt1--, cnt2--;
    }

    vi ts;

    cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == el1) cnt1++;
        if(v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if(cnt1 >= mini) ts.push_back(el1);
    if(cnt2 >= mini) ts.push_back(el2);

    // sort(ts.begin(), ts.end());
    // * TC: O(2log2) -> ~ O(1)

    return ts;
}


int main(){
    vi arr = {11, 33, 33, 11, 33, 11};
    vi ans = majelem(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    vi arr1 = {10, 20, 40, 20, 40, 20};
    vi ans1 = majelemBe(arr1);
    cout << "The majority elements are: ";
    for (auto it : ans1)
        cout << it << " ";
    cout << "\n";
    vi arr2 = {10, 20, 40, 20, 40, 20, 10, 10, 40, 40, 10};
    vi ans2 = majelemOA(arr2);
    cout << "The majority elements are: ";
    for (auto it : ans2)
        cout << it << " ";
    cout << "\n";
}