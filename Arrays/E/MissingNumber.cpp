#include<bits/stdc++.h>
using namespace std;

// $ Find the missing number from the array of 1 to N

// $ BFA
// $ TC: O(n^2) | SC: O(1)
int missingNumber(vector<int> &arr, int N) {
    for(int i = 1; i <= N; i++) {
        int flag = 0;
        for(int j = 0; j < N - 1; j++) {
            if(arr[j] == i) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) return i;
    }
    return -1;
}

// $ Better Approach
// $ TC: O(n) | SC: O(n)
int missingNumberBeA(vector<int> &arr, int N) {
    int hash[N + 1] = {0};

    for(int i = 0; i < N - 1; i++) {
        hash[arr[i]]++;
    }

    for(int i = 1; i <= N; i++) {
        if(hash[i] == 0) return i;
    }
    return -1;
}

// $ OA 1
// $ TC: O(n) | SC: O(1)
int missingNumberOA1(vector<int> &arr, int n) {
    int sum = (n * (n + 1)) / 2;
    int s2 = 0;
    for(int i = 0; i < n - 1; i++) {
        s2 += arr[i];
    }
    int missing = sum - s2;
    return missing;
}

// $ OA 2
// $ TC: O() | SC: O()


int main() {
    int N = 7;
    vector<int> a = {1, 2, 3, 4, 5, 6};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    int ans1 = missingNumberBeA(a, N);
    cout << "The missing number is: " << ans1 << endl;
    int ans2 = missingNumberOA1(a, N);
    cout << "The missing number is: " << ans2 << endl;
}