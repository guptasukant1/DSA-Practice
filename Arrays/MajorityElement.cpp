#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define miip map<int, int>

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

// $ Better Approach
int majorityElementBe(vi v){
    int n = v.size();
    miip mpp;
    
    for(int i = 0; i < n; i++){
        mpp[v[i]]++;
    }

    for(auto i: mpp){
        if(i.second > (n / 2)) return i.first;
    }
    return -1;
}


int main()
{
    vi arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    vi arr1 = {4, 4, 5, 6, 7, 4, 4, 4};
    int ans1 = majorityElementBe(arr1);
    cout << "The majority element is: " << ans1 << endl;
}