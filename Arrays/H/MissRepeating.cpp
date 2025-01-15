#include<bits/stdc++.h>
using namespace std;

// $ Find the missing and repeating numbers in array of 1 to n where A appears twice and B is missing

// $ BFA
// $ TC: O() | SC: O()
vector<int> findMissingRepeatingNumbers(vector<int> &arr) {
    int missing = -1, repeating = -1;
    for(int i = 1; i <= arr.size(); i++) {
        int count = 0;
        for(int j = 0; j < arr.size(); j++) {
            if(arr[j] == i) count++;
        }

        if(count == 2) repeating = i;
        else if(count == 0) missing = i;

        if(repeating != -1 && missing != -1) break;
    }
    return {repeating, missing};
}

// $ Better Approach
// 

int main() {
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {" << ans[0] << ", " << ans[1] << "}\n";
}