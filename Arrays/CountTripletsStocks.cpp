#include<bits/stdc++.h>
using namespace std;

// $ Counting Triplets Stocks divisible by d (IBM QUESTION PRAC)[CHECK OBSIDIAN FOR PS]

// $ OA 1
// $ TC: O(n^2) | SC: O(n*d)
int countDivisibleTriplets(const vector<int> &arr, int d){
    int n = arr.size();
    int count = 0;
    vector<unordered_map<int, int>> mpp(n);
    for(int j = 1; j < n - 1; j++){
        for(int i = 0; i < j; i++){
            int sum = (arr[i] + arr[j]) % d;
            mpp[j][sum]++;
        }
        for(int k = j + 1; k < n; k++){
            int target = (d - (arr[k] % d)) % d;
            count += mpp[j][target];
        }
    }
    return count;
}

// $ OA 2
// $ TC: O(n^2) | SC: O(d)
int countDivisibleTripletsOA(const vector<int> &arr, int d){
    int n = arr.size();
    int count = 0;

    unordered_map<int, int> mpp;
    for(int j = 1; j < n - 1; j++){
        for(int k = j + 1; k < n; k++){
            int reqRem = (d - (arr[k] % d)) % d;
            if(mpp.count(reqRem)) count += mpp[reqRem];
        }
        for(int i = 0; i < j; i++){
            int pairRem = (arr[i] + arr[j]) % d;
            mpp[pairRem]++;
        }
    }
    return count;
}

int main() {
	vector<int> arr = {3, 3, 4, 7, 8};
	int d = 5;
	cout << "Number of divisible triplets: " << countDivisibleTriplets(arr, d) << endl; // Output should be 3
	cout << "Number of divisible triplets: " << countDivisibleTripletsOA(arr, d) << endl; // Output should be 3
}