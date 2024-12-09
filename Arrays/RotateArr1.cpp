#include<bits/stdc++.h>
using namespace std;

// $ Rotate array by 1

// $ BFA
// $ TC: O(n) | SC: O(n)
void solve(int arr[], int n){
    int temp[n];
    for(int i = 1; i < n; i++){
        temp[i - 1] = arr[i];
    }
    temp[n - 1] = arr[0];
    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
}

// $ OA
// $ TC: O(n) | SC: O(1)
void solveOA(int arr[], int n){
    int temp = arr[0];
    for(int i = 1; i < n; i++){
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n=5;
    int arr[]= {1,2,3,4,5};
    solve(arr, n);
    solveOA(arr, n);
}