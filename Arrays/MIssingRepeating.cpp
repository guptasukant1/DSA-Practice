#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>


// $ Find the missing and repeating nos in an array of 1-n elements.
// $ Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.

// $ Brute Force Approach
// $ TC: O(N^2) | SC: O(1)
vi findMissingRep(vi a){
    int n = a.size();
    int repeating = -1, missing =  -1;

    for(int i = 1; i <= n; i++){
        int count = 0;
        for (int j = 0; j < n; j++){
            if(a[j] == i)
                count++;
        }
        if(count == 2)
            repeating = i;
        else if(count == 0)
            missing = i;
        if(repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}

// $ Better Approach [Hashing]
// $ TC: O(2*n) | SC: O(n)
vi findMissingRepBe(vi a){
    int n = a.size();
    vi hash(n + 1, 0);
    // * Set the hash arr with frequencies
    for (int i = 0; i < n; i++)
        hash[a[i]]++;

    int rep = -1, miss = -1;
    for(int i = 1; i <= n; i++){
        if(hash[i] == 2)
            rep = i;
        else if(hash[i] == 0)
            miss = i;

        if(rep != -1 && miss != -1)
            break;
    }
    return {rep, miss};
}

// $ Optimal Approach 1 [Maths [AP]]

vi findMissingRepO1(vi a){
    
}



int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRep(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    vector<int> a1 = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans1 = findMissingRepBe(a1);
    cout << "The repeating and missing numbers are: {"
         << ans1[0] << ", " << ans1[1] << "}\n";
    vector<int> a2 = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans2 = findMissingRep(a2);
    cout << "The repeating and missing numbers are: {"
         << ans2[0] << ", " << ans2[1] << "}\n";
    vector<int> a3 = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans3 = findMissingRep(a3);
    cout << "The repeating and missing numbers are: {"
         << ans3[0] << ", " << ans3[1] << "}\n";
    return 0;
}