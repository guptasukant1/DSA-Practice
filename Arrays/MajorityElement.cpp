#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define miip map<int, int>

// $ Majority Element in an array is an element that appears more than n/2 times in the array

// $ Brute-Force Approach
// $ TC: O(n^2) | SC: O(1)
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
// $ TC: O(nlogn) + O(n) | SC: O(n)
// $ We will use a map to store the frequency of each element. Iterate over the map and check if the frequency of any element is greater than n/2
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

// $ Optimal Approach [Moore's Voting Algo]
// $ TC: O(n) | SC: O(1)
// | We will keep track of a temporary majority element and its count. If the current element is equal to the temp majority element, we will increase the count, 
// | else we will decrease the count. If the count becomes 0, we will update the temp majority element to the current element and set the count to 1. 
// | At the end, we will check if the temp majority element is the majority element or not.
int majorityElementOA(vi v){
    int n = v.size();
    int count = 0;
    int el;

    for(int i = 0; i < n; i++){
        if(count == 0){
            count = 1;
            el = v[i];
        }
        else if(el == v[i]) count++;
        else count--;
    }
    // * Checking if the stored element is the majority element
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == el) cnt++;
    }
    if(cnt > (n / 2)) return el;
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
    int ans2 = majorityElementOA(arr1);
    cout << "The majority element is: " << ans2 << endl;
}