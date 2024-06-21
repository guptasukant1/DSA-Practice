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


// 


int main(){
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majelem(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}