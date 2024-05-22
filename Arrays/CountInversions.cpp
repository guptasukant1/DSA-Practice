#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
// $ Count the number of inversions in an array
// $ Inversion is a pair of indices i, j such that i < j and a[i] > a[j]

// $ Brute Force
// $ TC: O(N^2) | SC: O(1)
int countInversions(vi a){
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = i + 1; j < a.size(); j++){
            if(a[i] > a[j]) count++;
        }
    }
    return count;
}

// $ Optimal Approach[Merge Sort]



int main(){
    vector<int> a = {5, 4, 3, 2, 1};
    int cnt = countInversions(a);
    cout << "The number of inversions is: "
         << cnt << endl;
}