#include<bits/stdc++.h>
using namespace std;

// $ Check if the array is sorted or not

// $ OA
// $ TC: O(n) | SC: O(1)
bool isSorted(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]) return false;
    }
    return true;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}, n = 5;
    printf("%s", isSorted(arr, n) ? "True" : "False");
}
