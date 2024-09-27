#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Count Reverse Pairs. Reverse Pair: i < j && a[i] > 2 * a[j]

// $ Brute Force Approach
// $ TC: O(n^2) | SC: O(1)
int countPairs(vi &a, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > 2 * a[j]) count++;
        }
    }
    return count;
}

int team(vector <int> & skill, int n) {
    return countPairs(skill, n);
}

int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: " << cnt << endl;
}
