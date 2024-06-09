#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Majority Element in an array is an element that appears more than n/2 times in the array

// $ Brute-Force Approach
int majorityElement(vi v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(v[i] == v[j]) count++;
        }
        if(count > (n / 2)) return v[i];
    }
    return -1;
}

int main()
{
    vi arr = {2, 2, 1, 1, 1, 2, 3};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}