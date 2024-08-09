#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define svi set<vector<int>>
#define vi vector<int>

// $ Triplets adding up to zero

// $ Brute Force Approach
// $ TC: O(n^3 * log(no. of unique triplets)) | SC: O(2 * no. of unique triplets)
vvi tripletBF(int n, vi &arr){
    svi st;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    vi temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
            
        }
    }
    vvi ans(st.begin(), st.end());
    return ans;
}

// $ Better Approach [using hashset to store the elements between i & j and finding the third elem in it using the formula.]
// $ TC: O(n ^ 2 * log(no. of unique triplets)) | SC: O(2 * no. of unique triplets)
vvi tripletBeA(int n, vi &arr){
    svi st;

    for(int i = 0; i < n; i++){
        set<int> hashSet;
        for(int j = i + 1; j < n; j++){
            int third = -( arr[i] + arr[j] );
            if(hashSet.find(third) != hashSet.end()){ // * Returns an iterator to the element if found else returns end()
                vi temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }
    vvi ans(st.begin(), st.end());
    return ans;
}

// $ Optimal Approach
// $ TC: O() | SC: O()
vvi tripletOA(int n, vi &arr){
    vvi ans;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        if(i != 0 && arr[i - 1] == arr[i]) continue;
        int j = i + 1;
        int k = n - 1;
        while(j < k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum > 0) k--;
            else if(sum < 0) j++;
            else {
                vi temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && arr[j] == arr[j - 1]) j++;
                while(j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}


int main()
{
    vi arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vvi ans = tripletBF(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    vvi ans1 = tripletBeA(n, arr);
    for (auto it : ans1) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    vvi ans2 = tripletOA(n, arr);
    for (auto it : ans2) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}