#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>


// $ Find the missing and repeating nos in an array of 1-n elements.
// $ Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.

// $ Brute Force Approach
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
        if(repeating == -1 && missing == -1)
            break;
    }
    return {repeating, missing};
}



int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRep(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}