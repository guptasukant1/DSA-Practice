#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define svi set<vector<int>>
#define vi vector<int>

// $ Triplets adding up to zero

vvi triplet(int n, vi &arr){
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




int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}